---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference"
---

[[Dynamic Programming]]

# Problem 
Given an array and a difference, we need to find an AP in the array as a subsequence with the longest length.

# Solution
This problem is very similar to the [[Longest Increasing Subsequence]]. Except here we also need the number to be `arr[i] + difference`.
To make the algorithm faster we use a hash map to store all the previously calculated values to avoid looping twice

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

