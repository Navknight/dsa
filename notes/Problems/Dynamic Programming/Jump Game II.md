---
difficulty: Medium
topics:
  - Dynamic Programming
  - Greedy
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/jump-game-ii/description/
date: 2026-09-17
---

[[Dynamic Programming]] [[Greedy]] [[Arrays]]

# Problem
Array `nums`, each element is the max jump length from that index. Guaranteed you can reach the last index. Find the minimum number of jumps to get there.

# Approach
## Brute Force (Recursion)
From each index try every jump length 1..nums[i], recurse, take the min. Watch out for indices where nums[i] = 0 before the end, that branch is a dead end and must not be counted.

### Code
```cpp
int solve(vector<int>& nums, int ind) {
    if (ind >= (int)nums.size() - 1) return 0;
    int steps = INT32_MAX;
    for (int i = 1; i <= nums[ind]; i++) {
        int sub = solve(nums, ind + i);
        if (sub != INT32_MAX) steps = min(steps, sub);
    }
    return steps == INT32_MAX ? INT32_MAX : 1 + steps;
}

int jump(vector<int>& nums) {
    return solve(nums, 0);
}
```

### Complexity
- Time: $O(2^n)$ worst case, overlapping subproblems not cached
- Space: $O(n)$ recursion stack

## Bottom-Up DP
dp[i] = min jumps to reach the end from i. Fill from the back. From i, jump length j can only go up to min(nums[i], n-1-i), going past n-1 is out of bounds.

### Code
```cpp
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int maxJ = min(nums[i], n - 1 - i);
        for (int j = 1; j <= maxJ; j++) {
            if (dp[i + j] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i + j]);
        }
    }
    return dp[0];
}
```

### Complexity
- Time: $O(n^2)$ worst case
- Space: $O(n)$

## Greedy (Optimal)
Think of it as BFS levels. currentEnd = farthest reachable with the jumps used so far. Scan forward, track farthest = max reach seen so far. When i hits currentEnd, a jump is forced, bump jumps and set currentEnd = farthest.

### Code
```cpp
int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0, currentEnd = 0, farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    return jumps;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
