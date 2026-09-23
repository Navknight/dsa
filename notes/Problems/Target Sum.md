---
link: https://leetcode.com/problems/target-sum/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "P - N = target, P + N = sum, so count subsets with sum (sum + target) / 2"
time: "O(n * sum)"
space: "O(n * sum)"
date: 2026-09-01
---

# Problem
Ways to put `+` or `-` on each number to reach `target`.

# Approach
`P - N = target`, `P + N = sum`, so `P = (sum + target) / 2`. Count subsets summing to `P`, like [[Partition Equal Subset Sum]] with `+` instead of `||`.

## Recursion

### Code
```cpp
class Solution {
public:
    int solve(vector<int>& nums, int ind, int sum, int target) {
        if (nums.size() == ind && sum == target)
            return 1;
        else if (ind == nums.size())
            return 0;

        return solve(nums, ind + 1, sum - nums[ind], target) +
               solve(nums, ind + 1, sum + nums[ind], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};
```

### Complexity
- Time: $O(2^n)$
- Space: $O(n)$

## Subset Sum Count
`target = abs(target)`. Odd `sum + target` means 0 ways. `dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]]`.

### Code
```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int range = accumulate(nums.begin(), nums.end(), 0);

        target = abs(target);

        if ((range + target) % 2 != 0) return 0;
        int sum = (range + target) / 2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[nums.size()][sum];
    }
};
```

### Complexity
- Time: $O(n \cdot sum)$
- Space: $O(n \cdot sum)$
