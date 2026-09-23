---
link: https://leetcode.com/problems/partition-equal-subset-sum/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "odd sum = false, else subset sum to total/2 with 1D dp, j descending"
time: "O(n * target)"
space: "O(target)"
date: 2026-08-29
---

# Problem
Split into two subsets with equal sum?

# Approach
Odd total is impossible. Else find a subset summing to `total / 2`, 0/1 knapsack.

## Recursion
Assign each element to one of two subsets. TLE.

### Code
```cpp
bool solve(vector<int>& nums, int ind, int s1, int s2) {
    if (ind == nums.size()) return s1 == s2;
    return solve(nums, ind + 1, s1 + nums[ind], s2) ||
           solve(nums, ind + 1, s1, s2 + nums[ind]);
}
```

### Complexity
- Time: $O(2^n)$
- Space: $O(n)$

## 1D Subset Sum
`dp[j] |= dp[j - nums[i]]` with `j` descending, so each element is used once. Ascending turns it into unbounded knapsack.

### Code
```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= 0; j--) {
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};
```

### Complexity
- Time: $O(n \cdot target)$
- Space: $O(target)$
