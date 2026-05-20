---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/longest-arithmetic-subsequence"
code: ../../../LeetCode/longest_arithmetic_subsequence.cpp
---

[[Dynamic Programming]]

# Problem
Given an array `nums` of integers, return _the length of the longest arithmetic subsequence in_ `nums`.

**Note** that:

- A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
- A sequence `seq` is arithmetic if `seq[i + 1] - seq[i]` are all the same value (for `0 <= i < seq.length - 1`).

# Solution


```cpp
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    vector<unordered_map<int, int>> t(n);
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            if (t[j].find(diff) != t[j].end())
                t[i][diff] = t[j][diff] + 1;
            else
                t[i][diff] = 2;
            maxi = max(maxi, t[i][diff]);
        }
    }

    return maxi;
}
```