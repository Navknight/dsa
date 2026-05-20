---
difficulty: Medium
topics:
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/valid-sudoku/description/
date: 2026-05-18
code: ../../../LeetCode/Valid_sudoku.cpp
---
[[Arrays]]
# Problem
Validate if the matrix is a correct sudoku
# Approach
Brute force, just validate if a number is repeated in a row, column and a $3*3$ matrix. Main problem is figuring out the indices of the $3*3$ matrix.
# Code

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

# Complexity
- Time: $O(9^3)$ = $O(1)$ (fixed 9×9 board)
- Space: $O(1)$
