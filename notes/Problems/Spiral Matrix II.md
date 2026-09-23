---
link: https://leetcode.com/problems/spiral-matrix-ii/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "four boundaries, fill right, down, left, up and shrink each after its side"
time: "O(n²)"
space: "O(1)"
date: 2023-03-11
---

# Problem
Fill an `n x n` matrix with `1..n²` in spiral order.

# Approach
## Boundaries
Same walk as [[Spiral Matrix]], writing `count++` instead of reading.

### Code
```cpp
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int row = 0, col = 0;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;
    int count = 1;
    while (row_start <= row_end && col_start <= col_end)
    {
        while (col <= col_end)
        {
            matrix[row][col] = count;
            count++;
            col++;
        }
        row_start++;
        row++;
        col--;
        while (row <= row_end)
        {
            matrix[row][col] = count;
            count++;
            row++;
        }
        col_end--;
        col--;
        row--;
        while (col >= col_start)
        {
            matrix[row][col] = count;
            count++;
            col--;
        }
        row_end--;
        row--;
        col++;
        while (row >= row_start)
        {
            matrix[row][col] = count;
            count++;
            row--;
        }
        col_start++;
        col++;
        row++;
    }
    return matrix;
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(1)$ extra
