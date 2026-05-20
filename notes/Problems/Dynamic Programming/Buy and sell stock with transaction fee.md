---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/"
---

[[Dynamic Programming]]

# Problem
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note:**

- You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
- The transaction fee is only charged once for each stock purchase and sale.

# Solution
The solution is very similar to the [[Buy and Sell Stock with cooldown]] solution, except we don't skip the next element after selling and we also need to subtract the transactino fee from the profit on every sale.

```cpp
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> t(n + 1, vector<int>(2, 0));

    // 0 we can sell
    // 1 we can buy

    for (int i = n - 1; i >= 0; i--)
    {
        t[i][0] = max(prices[i] - fee + t[i + 1][1], t[i + 1][0]);
        t[i][1] = max(-prices[i] + t[i + 1][0], t[i + 1][1]);
    }

    return t[0][1];
}
```
