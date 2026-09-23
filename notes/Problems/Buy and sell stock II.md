---
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Greedy]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "add every positive day-to-day difference"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Unlimited transactions, hold at most one share. Max profit.

# Approach
## Greedy
Take every upswing: add `prices[i] - prices[i-1]` when positive.

### Code
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

### Complexity
- Time: $O(n)$
- Space: $O(1)$
