---
link: https://leetcode.com/problems/reshape-the-matrix/
difficulty: Easy
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "flat index i * n + j maps to (ind / c, ind % c)"
time: "O(m * n)"
space: "O(m * n)"
date: 2022-12-10
---

# Problem
Reshape an `m x n` matrix to `r x c`, return the original if impossible.

# Approach
## Flat Index
`ind = i * n + j`, target cell `(ind / c, ind % c)`.

### Code
```cpp
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int m = mat.size();
    int n = mat[0].size();
    if (r * c != m * n)
        return mat;
    vector<vector<int>> ans(r, vector<int>(c));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ind = i * n + j;
            ans[ind / c][ind % c] = mat[i][j];
        }
    }
    return ans;
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
