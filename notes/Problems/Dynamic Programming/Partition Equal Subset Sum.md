---
difficulty: Medium
topics:
  - Dynamic Programming
source: Leetcode
star: false
link: https://leetcode.com/problems/partition-equal-subset-sum/
date: 2026-08-29
---

[[Dynamic Programming]]

# Problem
Given an array of positive integers, determine if it can be split into two subsets with equal sum.

# Approach
If total sum is odd, impossible. Otherwise reduce to: does some subset sum to `total / 2`? The complement automatically forms the other equal-sum half. Classic 0/1 knapsack subset-sum.

## Brute Force (two-subset recursion)
Try assigning each element to subset 1 or 2, check equality at the end. $O(2^n)$, TLEs.

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

## Bottom-Up DP (subset sum)
`dp[j]` = can some subset sum to `j`. For each `nums[i]`, update `dp[j] |= dp[j - nums[i]]` for `j` from `target` down to `nums[i]`.

Iterating `j` **descending** is required: it guarantees `dp[j - nums[i]]` still holds the value from before this item was considered, so each element is used at most once. Ascending order lets the same element get reused within one pass (turns it into unbounded knapsack).

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
- Time: $O(n \cdot \text{target})$
- Space: $O(\text{target})$
