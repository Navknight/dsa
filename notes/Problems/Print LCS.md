---
link: https://www.geeksforgeeks.org/printing-longest-common-subsequence/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Strings]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "fill the LCS table, walk back from (n, m): match goes diagonal and takes the char, else go to the bigger neighbour"
time: "O(n * m)"
space: "O(n * m)"
date: 2023-07-24
---

# Problem
Print the longest common subsequence itself.

# Approach
## Backtrack the Table
Build the [[Longest Common Subsequence]] table. From `(n, m)`: chars match, take it and go diagonal. Else move toward the bigger of `t[i-1][j]` and `t[i][j-1]`.

### Code
```cpp
string printLCS(string a, string b, int n, int m)
{
    vector<vector<int>> t(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (a[i - 1] == b[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = n, j = m;
    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            i--;
            j--;
            ans = a[i] + ans;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
                i--;
            else
                j--;
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n \cdot m)$
