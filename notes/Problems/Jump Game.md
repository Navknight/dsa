---
link: https://leetcode.com/problems/jump-game/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Greedy]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "track farthest reachable, fail if i > farthest"
time: "O(n)"
space: "O(1)"
date: 2026-08-22
---

# Problem
Can you reach the last index?

# Approach
## DP
`dp[i]` = true if some reachable `j` has `dp[j]`.

Mistakes I made: wrote `dp[i];` instead of `dp[i] = true;`, and no `j < n` bound.

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
- Time: $O(n^2)$
- Space: $O(n)$

## Greedy
Track `farthest`. If `i > farthest`, `i` is unreachable.

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
