---
difficulty: Medium
topics: ["Dynamic Programming", "Greedy"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/"
---

[[Dynamic Programming]] [[Greedy]]

# Problem

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.

Find and return _the **maximum** profit you can achieve_.

# Solution

For maximum profit we will have to buy every time the price is low and sell at the subsequent time when it is high, other wise we will miss some intervals.

```cpp
int maxProfit(vector<int>& prices) {
        int ans = 0;int n = prices.size();
        for(int i = 1; i < n; i++){
            if(prices[i-1] < prices[i])
                ans += prices[i] - prices[i-1];
        }
        return ans;
}
```