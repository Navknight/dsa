---
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "same dp as stock III with cap going up to k"
time: "O(n * k)"
space: "O(k)"
date: 
---

# Problem
Max profit with at most `k` transactions.

# Approach
## DP (index, buy, cap)
[[Buy and Sell stock III]] with the cap going up to `k`.

### Code
```cpp
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(k+1, 0));
    vector<vector<int>> curr(2, vector<int>(k+1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy == 0)
                    curr[buy][cap] = max(-prices[i] + prev[1][cap], prev[0][cap]);
                if(buy == 1)
                    curr[buy][cap] = max(prices[i] + prev[0][cap - 1], prev[1][cap]);
            }
        }
        prev = curr;
}

return curr[0][k];
}
```

### Complexity
- Time: $O(n \cdot k)$
- Space: $O(k)$
