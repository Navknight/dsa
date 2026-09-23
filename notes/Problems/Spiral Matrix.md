---
link: https://leetcode.com/problems/spiral-matrix/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "walk right, down, left, up, shrinking the boundary by one layer each loop"
time: "O(m * n)"
space: "O(1)"
date: 2023-04-05
---

# Problem
Return the matrix in spiral order.

# Approach
## Layer by Layer
Walk right, down, left, up. `point` = layers done, shrinks the bounds. Resize at the end to drop overshoot on non-square matrices.

### Code
```cpp
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0, col = 0, point = 0;
    while (ans.size() < rows * cols)
    {
        for (col = col; col < cols - point; col++)
            ans.push_back(matrix[row][col]);
        row++;
        col--;
        for (row = row; row < rows - point; row++)
            ans.push_back(matrix[row][col]);
        col--;
        row--;
        for (col = col; col >= point; col--)
            ans.push_back(matrix[row][col]);
        row--;
        col++;
        point++;
        for (row = row; row >= point; row--)
            ans.push_back(matrix[row][col]);
        col++;
        row++;
    }
    ans.resize(rows*cols);
    return ans;
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(1)$
