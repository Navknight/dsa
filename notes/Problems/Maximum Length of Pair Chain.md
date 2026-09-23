---
link: https://leetcode.com/problems/maximum-length-of-pair-chain/
difficulty: Medium
topics:
  - "[[Greedy]]"
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "sort by end, greedily take a pair if its start > last end"
time: "O(n log n)"
space: "O(1)"
date: 
---

# Problem
Longest chain of pairs where `b < c` for consecutive pairs `[a,b], [c,d]`.

# Approach
## DP
Sort, then [[Longest Increasing Subsequence]] style.

### Code
```cpp
int findLongestChain(vector<vector<int>> &pairs)
{
    int n = pairs.size();
    int max_length = 1;
    sort(pairs.begin(), pairs.end());
    vector<int> t(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pairs[j][0] > pairs[i][1])
            {
                t[i] = max(t[i], 1 + t[j]);
            }
        }
        max_length = max(max_length, t[i]);
    }
    return max_length;
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$

## Greedy
Sort by end. Take a pair if its start > the last end. Smaller end leaves more room for later pairs.

### Code
```cpp
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });

    int n = pairs.size();
    int max_length = 0;
    int prev = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pairs[i][0] > prev)
        {
            max_length++;
            prev = pairs[i][1];
        }
    }

    return max_length;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
