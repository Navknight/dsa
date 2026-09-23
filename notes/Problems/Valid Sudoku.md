---
link: https://leetcode.com/problems/valid-sudoku/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "check rows, cols and boxes for repeats. box index = (i / 3) * 3 + j / 3"
time: "O(1)"
space: "O(1)"
date: 2026-05-18
---

# Problem
Is a partially filled sudoku board valid?

# Approach
## Check Each Unit
No repeats in any row, column or 3x3 box. Box index `(i / 3) * 3 + j / 3`.

### Code
```cpp
bool isValidSudoku(vector<vector<char>>& board) {
    int r = board[0].size();
    int c = board.size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '.')
                continue;
            for (int k = 0; k < c; k++) {
                if (k != i && board[i][j] == board[k][j])
                    return false;
            }

            for (int k = 0; k < r; k++) {
                if (k != j && board[i][j] == board[i][k])
                    return false;
            }

            for (int ii = i / 3 * 3; ii < (i + 3) / 3 * 3; ii++) {
                for (int jj = j / 3 * 3; jj < (j + 3) / 3 * 3; jj++) {
                    if ((ii != i || jj != j) && board[ii][jj] == board[i][j])
                        return false;
                }
            }
        }
    }

    return true;
}
```

### Complexity
- Time: $O(1)$, fixed 9x9
- Space: $O(1)$
