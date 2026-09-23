---
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
difficulty: Easy
topics:
  - "[[Two Pointers]]"
  - "[[Sliding Window]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "track the min price so far, profit = price - min"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
One buy and one sell, max profit.

# Approach
## Two Pointers
Move `left` to any lower price, it's always a better buy for the days after. Otherwise check profit `prices[r] - prices[l]`.

### Code
```cpp
int maxProfit(vector<int>& prices) {
    int left = 0, right = left + 1;
    int ans = 0;
    while(right < prices.size()){
        if(prices[right] < prices[left]){
            left = right;
        } else {
            ans = max(ans, prices[right] - prices[left]);
        }
        right++;
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
