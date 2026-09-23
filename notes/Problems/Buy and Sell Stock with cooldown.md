---
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "on sell jump to i + 2, dp[i][canBuy]"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Unlimited transactions, one day cooldown after selling.

# Approach
## Recursion
[[Buy and sell stock II]] but skip the next day after a sell.

### Code
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

### Complexity
- Time: $O(2^n)$
- Space: $O(n)$

## DP
`t[i][0]` = can buy, `t[i][1]` = can sell. Selling jumps to `i + 2`.

### Code
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

### Complexity
- Time: $O(n)$
- Space: $O(n)$
