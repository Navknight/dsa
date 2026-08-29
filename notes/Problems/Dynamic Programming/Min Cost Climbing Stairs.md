---
difficulty: Easy
topics:
  - Dynamic Programming
source: Leetcode
star: false
code: LeetCode/min_cost_climbing_stairs.cpp
link: https://leetcode.com/problems/min-cost-climbing-stairs/
date: 2026-08-29
---

[[LeetCode/min_cost_climbing_stairs.cpp]]
[[Dynamic Programming]]

# Problem
Given `cost[i]` to step off stair `i`, starting from step `0` or `1` (free), reach the top (one past the last stair) for minimum total cost. Each step moves 1 or 2 stairs.

# Approach
`dp[i]` = min cost to reach the top starting from stair `i`. `dp[i] = cost[i] + min(dp[i+1], dp[i+2])`, with `dp[n] = dp[n+1] = 0` (already past the top). Answer is `min(dp[0], dp[1])` since both starting stairs are free.

## Top-down with memoization
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
- Space: $O(n)$ (memo + recursion stack)

## Bottom-up, O(1) space
`dp[i]` only depends on `dp[i+1]` and `dp[i+2]` — no need to store the whole table, just the last two values.

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
