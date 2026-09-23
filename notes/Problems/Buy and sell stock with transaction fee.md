---
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "cooldown dp without the skip, subtract fee on sell"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Unlimited transactions, pay `fee` per transaction.

# Approach
## DP
Same as [[Buy and Sell Stock with cooldown]] without the skip. Subtract `fee` on every sell.

### Code
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

### Complexity
- Time: $O(n)$
- Space: $O(n)$
