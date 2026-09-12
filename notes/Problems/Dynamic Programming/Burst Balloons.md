---
difficulty: Hard
topics:
  - Dynamic Programming
source: Leetcode
star: true
link: https://leetcode.com/problems/burst-balloons
date: 2026-09-13
---

[[Dynamic Programming]]

# Problem
`n` balloons with values `nums`. Bursting `i` gives `left * nums[i] * right` using current neighbours (out of bounds counts as 1). Return max coins from bursting all.

# Approach
## Interval DP (burst last)
Pick `i` as the **last** balloon burst in `[l, r]`. Everything else in the range is gone by then, so its neighbours are `l-1` and `r+1`, not `i-1` and `i+1`.

Bursting last keeps the sides independent. `i` stays alive while `[l, i-1]` and `[i+1, r]` get burst, so it acts as a wall for both. Bursting first would make the two sides neighbours.

`dp[l][r] = max over i of nums[l-1]*nums[i]*nums[r+1] + dp[l][i-1] + dp[i+1][r]`

Pad `nums` with 1 at both ends so no bounds checks. Real balloons at `1..n`, answer at `dp[1][n]`.

Fill order: `dp[l][i-1]` has smaller r, `dp[i+1][r]` has bigger l. So l goes down, r goes up.

Mistakes I made: used `nums[i-1]`/`nums[i+1]` as neighbours, and a `r - l == 1` base case that ignored the outside neighbours.

### Code
```cpp
class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int l = n; l >= 1; l--) {
            for (int r = l; r <= n; r++) {
                for (int i = l; i <= r; i++) {
                    int value = nums[l - 1] * nums[i] * nums[r + 1];
                    dp[l][r] = max(dp[l][r], value + dp[l][i - 1] + dp[i + 1][r]);
                }
            }
        }
        return dp[1][n];
    }
};
```

### Complexity
- Time: $O(n^3)$
- Space: $O(n^2)$
