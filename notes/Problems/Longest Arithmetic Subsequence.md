---
link: https://leetcode.com/problems/longest-arithmetic-subsequence/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "dp[i][diff] = dp[j][diff] + 1 for every j < i"
time: "O(n²)"
space: "O(n²)"
date: 2023-08-14
---

# Problem
Length of the longest arithmetic subsequence.

# Approach
## DP on (index, diff)
`t[i][diff] = t[j][diff] + 1` for every `j < i`, else 2.

### Code
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

### Complexity
- Time: $O(n^2)$
- Space: $O(n^2)$
