---
difficulty: Medium
topics:
  - Dynamic Programming
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/longest-increasing-subsequence/
code: LeetCode/longest_increasing_subsequence.cpp
date: 2026-08-22
---

[[LeetCode/longest_increasing_subsequence.cpp]]
[[Dynamic Programming]] [[Recursion]]

# Problem
Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

# Approach
First instinct to rule out: a single running "tip" (max value + length seen so far), greedily extending or restarting, doesn't work. Traced on `nums=[1,2,100,4,5,6]` (true LIS is `[1,2,4,5,6]`, length `5`): once `100` overwrites the tip as `(max=100, len=3)`, the earlier state `(max=2, len=2)` — the one `4,5,6` could actually have extended to reach length `5` — is gone for good. A single scalar pair can't hold multiple candidate "best endings" open at once.

## Brute Force Recursion
Try every include/exclude choice: at each element, if it's smaller than the last-taken value (`maxi`), either take it (and recurse with the new `maxi`) or skip it; otherwise it must be skipped. Exponential — every element doubles the branching.

### Code
```cpp
int help(vector<int> &nums, int n, int maxi)
{
    if (n == 0)
        return 0;
    else
    {
        if (nums[n - 1] < maxi)
            return max(help(nums, n - 1, nums[n - 1]) + 1, help(nums, n - 1, maxi));
        else
            return help(nums, n - 1, maxi);
    }
}

int lengthOfLIS(vector<int> &nums)
{
    return help(nums, nums.size(), INT32_MAX);
}
```

### Complexity
- Time: $O(2^n)$
- Space: $O(n)$ recursion stack

## Bottom-Up DP
`ans[i]` = length of the longest increasing subsequence ending *exactly* at index `i`. For each `i`, scan every earlier `j < i`: if `nums[j] < nums[i]`, `i` could extend whatever subsequence ends at `j`, so `ans[i] = max(ans[i], ans[j] + 1)`. Base case `ans[i] = 1` (every element is trivially a length-1 subsequence on its own).

Bug hit along the way: first attempt returned `ans[n-1]` — the LIS ending at the *last* index — instead of the maximum across the whole array. The true LIS doesn't have to end at the last element. Traced on `nums=[1,3,6,7,2]` (true LIS is `[1,3,6,7]`, length `4`): `ans=[1,2,3,4,2]`, so `ans[n-1]=ans[4]=2` — wrong. The last element (`2`) just happens to be a bad tail that breaks the increasing trend; the real answer is sitting in `ans[3]`. Fixed by taking `max` over the entire `ans` array instead.

This is 1D DP — one index is the whole state, `ans[i]` built from `ans[j]` for all earlier `j`. It tops out at $O(n^2)$ since each of the `n` states requires scanning up to `n` earlier ones; going faster requires a different paradigm entirely (patience sorting / greedy + binary search), not a "better" DP.

### Code
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1e9);
        ans[0] = 1;

        for (int i = 1; i < n; i++) {
            ans[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    ans[i] = max(ans[j] + 1, ans[i]);
                }
            }
        }

        int a = -1e9;
        for (auto i : ans) a = max(a, i);
        return a;
    }
};
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$

## Patience Sorting (O(n log n))
Not DP — no recurrence, no reused subproblem table. Maintain `tails`, where `tails[k]` = the smallest possible tail value among all increasing subsequences of length `k+1` found so far (always sorted). For each new `x`, binary search for the first position `>= x`: if none exists, `x` extends the longest subsequence found so far (`push_back`); otherwise `x` replaces that position, since a smaller tail for the same length is always at least as useful for future extensions.

Why `tails.size()` is correct even though `tails` itself usually isn't a real subsequence: `size` only grows when a genuinely longer subsequence is discovered (the `push_back` case — `x` really does extend the current best tail into something one longer), and a replacement never grows `size`, it only improves a length's tail for later. So `size` tracks the true LIS length exactly, without ever overstating it.

Traced on `nums=[1,3,6,7,2]`: `tails` ends as `[1,2,6,7]`, and `size=4` matches the true LIS length. But `(1,2,6,7)` is **not** an actual subsequence of `nums` — to get `2` you need index `4`, which comes *after* `6` and `7` at indices `2,3`. The `2` overwrote the tail for length `2` (originally `3`, from `(1,3)`), improving future extensibility, but that overwrite mixes indices from unrelated partial subsequences into one array. `tails` is bookkeeping for lengths, not a real answer sequence — only its size is trustworthy.

### Code
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }
        return tails.size();
    }
};
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$ for `tails`
