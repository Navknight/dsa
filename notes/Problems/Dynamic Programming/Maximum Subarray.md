---
difficulty: Medium
topics:
  - Dynamic Programming
  - Greedy
source: Leetcode
star: false
link: https://leetcode.com/problems/maximum-subarray/
date: 2026-08-22
---

[[Dynamic Programming]] [[Greedy]]

# Problem
Given an integer array `nums`, find the contiguous subarray with the largest sum, and return that sum.

# Approach
## Kadane's Algorithm
This is one of the rare problems where a valid DP recurrence and a valid greedy rule coincide.

**DP view**: `dp[i]` = max sum of a subarray ending exactly at index `i`. `dp[i] = max(nums[i], nums[i] + dp[i-1])` — either start fresh at `nums[i]` alone, or extend the best subarray ending at `i-1`. 1D DP, single index state, same shape as House Robber/Climbing Stairs.

**Greedy view**: maintain a running sum; the moment it goes negative, discard it and start fresh from the next element, since a negative running sum can only ever hurt whatever gets added to it afterward. This is a provable, always-safe local decision — unlike Coin Change (`coins=[1,3,4], amount=6`: greedily grabbing the biggest coin gives `4+1+1`, but `3+3` is better — no safe local rule exists) or Longest Increasing Subsequence (a single running "tip" can't hold multiple candidate subsequence-endings open at once — discarding the "worse-looking" one can silently lose the one that mattered later). Kadane's avoids both failure modes because the reset decision only ever depends on one immediately-preceding value, and dropping a negative prefix is always safe with no hidden future dependency.

Important: the final answer is the max across *every* `dp[i]`, not just `dp[n-1]` — same trap as [[Longest Increasing Subsequence]]'s bug. The best subarray doesn't have to end at the last element, so track a running `ans` throughout the loop rather than returning the last computed value alone.

### Code
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev1 = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = max(nums[i], nums[i] + prev1);
            ans = max(ans, curr);
            prev1 = curr;
        }

        return ans;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
