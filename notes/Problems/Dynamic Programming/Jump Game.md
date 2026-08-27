---
difficulty: Medium
topics:
  - Dynamic Programming
  - Greedy
source: Leetcode
star: false
link: https://leetcode.com/problems/jump-game/
date: 2026-08-22
---

[[Dynamic Programming]] [[Greedy]]

# Problem
Given an array `nums` where `nums[i]` is the max jump length from index `i`, return whether you can reach the last index starting from index `0`.

# Approach
## Bottom-Up DP
`dp[i]` = can the last index be reached starting from `i`. `dp[n-1] = true` (already there). For `i` from `n-2` down to `0`, `dp[i]` is true if some `j` with `i < j <= i + nums[i]` has `dp[j]` true.

Bugs hit along the way:
- `dp[i];` instead of `dp[i] = true;` — a bare expression statement that reads `dp[i]` and discards it, doing nothing. Since everything defaults to `false` except the explicit `dp[n-1] = true`, this meant the "reachable" signal never actually propagated backward at all. Traced on `nums=[2,3,1,1,4]` (expected `true`): every `dp[i]` for `i < n-1` stayed `false`, so `dp[0]` incorrectly came out `false`.
- No `j < n` bound on the inner loop alongside `j - i <= nums[i]` — if `nums[i]` is large enough to overshoot the array, `j` walks past the last valid index. Traced on `nums=[2,0]`: at `i=0`, the loop would attempt `dp[2]` on a size-`2` vector — undefined behavior, not just a wasted check.

### Code
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j - i <= nums[i] && j < n; j++) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
```

### Complexity
- Time: $O(n^2)$ worst case — each `i` can scan up to `nums[i]` further positions
- Space: $O(n)$ for `dp`

## Greedy (Optimal)
Track the single farthest index reachable so far, scanning left to right. `farthest` only needs to be one number: reaching a farther index always subsumes reaching any nearer one, so there's no need to track multiple candidate frontiers (contrast with [[Longest Increasing Subsequence]], where a single running "tip" specifically does *not* suffice, since multiple candidate subsequence-endings can matter later).

`if (i > farthest) return false` is what keeps the greedy valid — it guarantees `i` itself is already confirmed reachable before using it to extend `farthest`, so `farthest = max(farthest, i + nums[i])` is always a legitimate extension.

Traced on `nums=[2,3,1,1,4]`: `farthest` climbs `0→2→4→4→4→8`, `i` never exceeds it, returns `true`. Traced on `nums=[3,2,1,0,4]` (expected `false`): `farthest` gets stuck at `3`, and at `i=4`, `4 > 3` triggers early `false`.

### Code
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n; i++) {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
