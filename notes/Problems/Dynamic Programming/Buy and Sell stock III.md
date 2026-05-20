---
difficulty: Hard
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii"
---

[[Dynamic Programming]]

# Problem 
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete **at most two transactions**.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

# Solution
Similar to [[Buy and Sell Stock with cooldown]] but we dont have a cooldown, instead we have a limited number of transactions available.
To tackle this we can use a 3D DP Table where there are 3 Dimensions - the index, the state i.e. buy or sell and the number of transactions we have left.

But since we only ever use the previous elements answers in the dp approach, we only need 2 2D tables - Prev and Curr.
```cpp
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy == 0)
                    curr[buy][cap] = max(-prices[i] + prev[1][cap], prev[0][cap]);
                if(buy == 1)
                    curr[buy][cap] = max(prices[i] + prev[0][cap - 1], prev[1][cap]);
            }
        }
        prev = curr;
    }

    return curr[0][2];
}
```
