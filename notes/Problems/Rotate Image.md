---
link: https://leetcode.com/problems/rotate-image/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery: yellow
review: 2026-11-11
insight: "rotate 4 cells at a time, layer by layer from the outside in"
time: "O(n²)"
space: "O(1)"
date: 2023-03-11
---

# Problem
Rotate an `n x n` matrix 90 degrees clockwise in place.

# Approach
## Layer Swaps
For each layer, cycle 4 cells at a time: bottom-left to top-left, bottom-right to bottom-left, top-right to bottom-right, saved top-left to top-right. Transpose + reverse each row also works.

### Code
```cpp
void rotate(vector<vector<int>> &matrix)
{
    int left = 0;
    int right = matrix.size() - 1;
    while (left < right)
    {
        int top = left;
        int bottom = right;
        for (int i = 0; i < right - left; i++)
        {
            // saving the top left element in a temporary variable
            int topLeft = matrix[top][left + i];

            // moving bottom left to top left
            matrix[top][left + i] = matrix[bottom - i][left];

            // moving bottom right to bottom left
            matrix[bottom - i][left] = matrix[bottom][right - i];

            // moving top right to bottom right
            matrix[bottom][right - i] = matrix[top + i][right];

            // moving the top left element in the temp variable to top right
            matrix[top + i][right] = topLeft;
        }
        right -= 1;
        left += 1;
    }
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(1)$

## Transpose + Reverse Rows
Cell `(r, c)` goes to `(c, n-1-r)`. Transpose sends it to `(c, r)`, reversing the row sends it to `(c, n-1-r)`. Shorter and harder to get wrong than the 4-cell cycle.

- Reverse each row for clockwise. Reversing each column gives counterclockwise
- Transpose loop starts at `j = i`, or `j = i + 1`. Swapping both triangles undoes itself

### Mistakes
- Said reverse each column first, that is counterclockwise

### Code
```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);

    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(1)$
