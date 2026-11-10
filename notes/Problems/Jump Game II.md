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
mastery: yellow
review: 2026-11-10
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

Mistakes I made (re-solve 2026-11-07):
- Counted a jump every time `farthest` improved. Indices in the same level share one jump, so only charge at the level boundary `i == currentEnd`. Failed on `[1,2,3,4,5]` (answer 3).
- Started `end = nums[0]` with `ans = 0`, which skips the first jump. Start `end = 0` so the jump out of index 0 is charged at `i = 0`.
- Patched the last jump with `|| i == n-1`. It works only because it cancels the missing first jump. Loop to `n - 2` instead, no jump is taken from the last index.
- Update `farthest` before the `i == end` check.
- The `n == 1` and `n == 2` special cases are not needed.

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
