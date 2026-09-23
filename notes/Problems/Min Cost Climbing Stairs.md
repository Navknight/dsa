---
link: https://leetcode.com/problems/min-cost-climbing-stairs/
difficulty: Easy
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "dp[i] = cost[i] + min(dp[i+1], dp[i+2]), answer min(dp[0], dp[1])"
time: "O(n)"
space: "O(1)"
date: 2026-08-29
---

# Problem
Min cost to reach the top, start at step 0 or 1, move 1 or 2.

# Approach
`dp[i] = cost[i] + min(dp[i+1], dp[i+2])`, past the top = 0. Answer `min(dp[0], dp[1])`.

## Memoization

### Code
```cpp
class Solution {
public:
    unordered_map<int, int> mp;
    int solve(vector<int>& cost, int ind) {
        if (ind >= cost.size()) return 0;
        if (ind >= cost.size() - 2) return cost[ind];
        if (mp.find(ind) != mp.end()) return mp[ind];
        return mp[ind] = cost[ind] + min(solve(cost, ind + 1), solve(cost, ind + 2));
    }
    int minCostClimbingStairs(vector<int>& cost) { return min(solve(cost, 0), solve(cost, 1)); }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Two Variables

### Code
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = 0, prev2 = 0;

        for (int i = n - 1; i >= 0; i--) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
