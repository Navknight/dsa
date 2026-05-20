---
difficulty: Medium
topics: ["Dynamic Programming", "Recursion"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/"
---

[[Dynamic Programming]] [[Recursion]]

# Problem
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

# Solution
This problem is related to the [[Buy and sell stock II]] problem, but with a cooldown. 

###  
The recursive solution is simple, we just skip the next element if we sell a stock on the current one.
```cpp
int help(vector<int> &prices, int i, int prev, int profit)
{
    if (i >= prices.size())
        return profit;
    else
    {
        if (prev == -1)
            return max(help(prices, i + 1, prices[i], profit), help(prices, i + 1, prev, profit));
        else
        {
            if (prices[i] > prev)
                return max(help(prices, i + 2, -1, profit + prices[i] - prev), help(prices, i + 1, prev, profit));
            else
                return help(prices, i + 1, prev, profit);
        }
    }
}

int maxProfit(vector<int> &prices)
{
    return help(prices, 0, -1, 0);
}
```


###  Approach
For the DP table approach we need to maintain states, that is we can have two states - either we are selling stock or we can buy stock.
So we maintain a dp table where one column is the index and the other is the state we are in on that index.

```cpp
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> t(n + 2, vector<int>(2, 0));

    // 0 is when we buy
    // 1 is when we sell

    for (int i = n - 1; i >= 0; i--)
    {
        t[i][0] = max(-prices[i] + t[i + 1][1], 0 + t[i + 1][0]);
        t[i][1] = max(prices[i] + t[i + 2][0], 0 + t[i + 1][1]);
    }

    return t[0][0];
}
```
Here, 0th column in the table denotes that we can buy stock and the 1st column denotes we can sell