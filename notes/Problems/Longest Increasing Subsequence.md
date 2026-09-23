---
link: https://leetcode.com/problems/longest-increasing-subsequence/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "tails[k] = smallest tail of an increasing subsequence of length k+1, lower_bound and replace"
time: "O(n log n)"
space: "O(n)"
date: 2026-08-22
---

# Problem
Length of the longest strictly increasing subsequence.

# Approach
One running tip doesn't work: `[1,2,100,4,5,6]` loses `(2, len 2)` once 100 comes.

## Recursion
Take if smaller than the last taken, or skip.

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
- Space: $O(n)$

## DP
`ans[i]` = LIS ending at `i` = `max(ans[j] + 1)` over `j < i` with `nums[j] < nums[i]`.

Mistake I made: returned `ans[n-1]`, the answer is the max over all `i`.

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

## Patience Sorting
`tails[k]` = smallest tail of any increasing subsequence of length `k+1`. `lower_bound`, replace or push. Only `tails.size()` is meaningful, `tails` isn't a real subsequence.

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
- Space: $O(n)$
