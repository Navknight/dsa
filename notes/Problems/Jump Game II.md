---
link: https://leetcode.com/problems/jump-game-ii/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Greedy]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "BFS levels: when i hits currentEnd, jump and set currentEnd = farthest"
time: "O(n)"
space: "O(1)"
date: 2026-09-17
---

# Problem
Min jumps to reach the last index.

# Approach
## Recursion
Try every jump length, take the min. Skip dead ends (`nums[i] = 0`).

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
- Time: $O(2^n)$
- Space: $O(n)$

## DP
`dp[i]` = min jumps from `i`, fill from the back. Cap `j` at `n - 1 - i`.

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
- Time: $O(n^2)$
- Space: $O(n)$

## Greedy
Track `farthest`. When `i == currentEnd` a jump is forced: `jumps++`, `currentEnd = farthest`.

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
