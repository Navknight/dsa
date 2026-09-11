---
difficulty: Medium
topics:
  - Dynamic Programming
source: Leetcode
star: false
link: https://leetcode.com/problems/target-sum/
date: 2026-09-01
---

[[Dynamic Programming]]

# Problem
Given an array of non-negative integers `nums` and an integer `target`, assign a `+` or `-` sign to every element so the resulting sum equals `target`. Return the number of ways to do it.

# Approach
Every sign assignment splits `nums` into two disjoint groups: `P` (positive-assigned) and `N` (negative-assigned), with `P - N = target` and `P + N = range` (the total sum of `nums`). Adding these gives `P = (range + target) / 2` — so counting sign assignments reduces to counting subsets of `nums` that sum to exactly `P`. Same reduction technique as [[Partition Equal Subset Sum]], but counting subsets instead of just checking reachability.

## Brute Force (Recursion)
Enumerate every sign assignment directly — branch `+`/`-` at each index, check the final sum against `target`. Correct, but exponential; only survives because `nums.length <= 20`.

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
- Space: $O(n)$ recursion stack

## Reduction to Subset-Sum Counting (Optimal)
`target = abs(target)` first — flipping every sign in an assignment maps ways-to-hit-`target` onto ways-to-hit-`-target` one-to-one, so only the non-negative case needs solving. If `range + target` is odd, `P` isn't a whole number and no assignment can work — return `0`.

`dp[i][j]` = number of subsets of the first `i` elements of `nums` summing to `j`. Every subset either excludes `nums[i-1]` (`dp[i-1][j]`) or includes it (`dp[i-1][j - nums[i-1]]`, only valid if it fits) — these are disjoint sets of subsets, so their counts add. This is why it's `+` here where `Partition Equal Subset Sum` uses `||`: that problem only asks if a subset exists, this one asks how many.

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
- Time: $O(n \times \text{sum})$, where $\text{sum} = (\text{range}+\text{target})/2 \le \text{range}$
- Space: $O(n \times \text{sum})$ — see [[Partition Equal Subset Sum]] for the 1D space-optimized version of this same reduction (drop to $O(\text{sum})$ by collapsing the row dimension)
