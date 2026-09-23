---
link: https://leetcode.com/problems/minimum-falling-path-sum/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "from the bottom row up, t[i][j] = val + min of the three cells below"
time: "O(n²)"
space: "O(n²)"
date: 2023-06-02
---

# Problem
Min sum path from top to bottom, each step goes down, down-left or down-right.

# Approach
## Bottom-Up DP
Start with the last row. `t[i][j] = matrix[i][j] + min(t[i+1][j-1], t[i+1][j], t[i+1][j+1])`. Answer is the min of row 0.

### Code
```cpp
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> t(m, vector<int>(n, 0));
    t.back() = matrix.back();

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = matrix[i][j] + min(t[i + 1][j], min((j + 1 < n) ? t[i + 1][j + 1] : INT32_MAX, (j - 1 >= 0) ? t[i + 1][j - 1] : INT32_MAX));
        }
    }

    sort(t[0].begin(), t[0].end());
    return t[0][0];
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n^2)$
