---
link: https://leetcode.com/problems/maximal-square/
difficulty: Medium
topics:
  - "[[Arrays]]"
  - "[[Recursion]]"
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "dp[i][j] = 1 + min(right, down, diag) if cell is 1"
time: "O(m * n)"
space: "O(n)"
date: 2023-06-03
---

# Problem
Area of the largest square of 1s.

# Approach
## DP, 1D
Cell as the top-left corner: side = `1 + min(right, down, diag)` if it's 1. Fill from the bottom-right with one row `t` and `prev` for the diagonal.

### Code
```cpp
int maximalSquare(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int maxSquareSize = 0;
    int prev = 0;
    vector<int> t(n, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int temp = t[j];
            if (i == m - 1 || j == n - 1)
                t[j] = matrix[i][j] - '0';
            else if (matrix[i][j] != '0')
                t[j] = matrix[i][j] + min(t[j], min(prev, t[j + 1])) - '0';
            else    
                t[j] = 0;

            if (t[j] > maxSquareSize)
                maxSquareSize = t[j];
            prev = temp;
        }
    }
    return maxSquareSize * maxSquareSize;
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(n)$
