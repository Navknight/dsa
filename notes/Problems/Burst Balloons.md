---
link: https://leetcode.com/problems/burst-balloons/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
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
