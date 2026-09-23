---
link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Strings]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "LCS table but a mismatch resets to 0, answer is the max cell"
time: "O(n * m)"
space: "O(n * m)"
date: 2023-07-22
---

# Problem
Length of the longest common contiguous substring.

# Approach
## LCS Variant
Like [[Longest Common Subsequence]], match = `1 + t[i-1][j-1]`, mismatch = 0. Track the max over the whole table.

### Code
```cpp
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    int max = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    if (t[i][j] > max)
                        max = t[i][j];
                }
                else
                    t[i][j] = 0;
            }
        }
    }
    return max;
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n \cdot m)$
