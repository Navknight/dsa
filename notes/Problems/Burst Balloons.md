---
link: https://leetcode.com/problems/burst-balloons/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery: red
review: 2026-11-10
insight: "pick i as the LAST burst in [l, r], neighbours are l-1 and r+1"
time: "O(n³)"
space: "O(n²)"
date: 2026-09-13
---

# Problem
Bursting `i` gives `left * nums[i] * right` with current neighbours (out of bounds = 1). Max coins from bursting all.

# Approach
## Interval DP (burst last)
Pick `i` as the **last** balloon burst in `[l, r]`. Its neighbours are then `l-1` and `r+1`. `i` stays alive while both sides get burst, so the sides stay independent.

`dp[l][r] = max over i of nums[l-1]*nums[i]*nums[r+1] + dp[l][i-1] + dp[i+1][r]`

Pad `nums` with 1 at both ends. Fill l going down, r going up.

- `dp[l][r]` covers `l..r` inclusive, `l-1` and `r+1` stay as the neighbours. Cells with `l > r` stay 0, they are the empty sides
- Fill `l` going down and `r` going up, no loop by length needed
- Can start the max at 0, coins are non-negative

### Mistakes
- Thought it was House Robber. The neighbours change as balloons pop, so a 1D take/skip DP can't work
- Thought about which balloon to burst first. That doesn't split the range, the two sides still touch. Pick the last one
- First draft put the 1s in the `dp` border instead of a padded `nums`, and had no transition
- Used `nums[i-1]`/`nums[i+1]` as neighbours, and a `r - l == 1` base case that ignored the outside neighbours

### Code
```cpp
class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> nums2(n + 2, 1);
        for (int i = 0; i < n; i++) {
            nums2[i + 1] = nums[i];
        }

        for (int l = n; l >= 1; l--) {
            for (int r = l; r <= n; r++) {
                int maxcoins = 0;
                for (int i = l; i <= r; i++) {
                    maxcoins = max(maxcoins, nums2[l - 1] * nums2[i] * nums2[r + 1] + dp[l][i - 1] + dp[i + 1][r]);
                }
                dp[l][r] = maxcoins;
            }
        }

        return dp[1][n];
    }
};
```

### Complexity
- Time: $O(n^3)$
- Space: $O(n^2)$
