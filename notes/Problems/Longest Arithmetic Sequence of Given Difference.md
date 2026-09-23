---
link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "dp[x] = dp[x - diff] + 1 in a hashmap"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Longest subsequence that is an AP with the given difference.

# Approach
## Hashmap DP
Like [[Longest Increasing Subsequence]] but the previous value is fixed: `dp[x] = dp[x - diff] + 1`.

### Code
```cpp
int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();
    unordered_map<int, int> t;
    int max_length = 1;

    for (int i = 0; i < n; i++)
    {
        if (t.find(arr[i] - difference) != t.end())
        {
            t[arr[i]] = t[arr[i] - difference] + 1;
        }
        else
            t[arr[i]] = 1;
        max_length = max(max_length, t[arr[i]]);
    }
    return max_length;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
