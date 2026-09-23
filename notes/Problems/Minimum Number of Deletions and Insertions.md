---
link: https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Strings]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "deletions = n - LCS, insertions = m - LCS"
time: "O(n * m)"
space: "O(n * m)"
date: 2023-07-27
---

# Problem
Min deletions and insertions to turn `str1` into `str2`.

# Approach
## LCS
Keep the LCS, delete the rest of `str1` (`n - l`), insert the rest of `str2` (`m - l`). Same as [[Delete Operation for Two Strings]].

### Code
```cpp
int minOperations(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (j == 0 || i == 0)
                t[i][j] = 0;
            else
            {
                if (str1[i - 1] == str2[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    int l = t[n][m];

    return ((l == m) ? (n - l) : (n - l + m - l));
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n \cdot m)$
