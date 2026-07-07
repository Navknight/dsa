---
difficulty: Hard
topics:
  - Backtracking
source: Leetcode
star: true
link: https://leetcode.com/problems/n-queens/
date: 2026-07-01
---

[[Backtracking]]

# Problem
Place N queens on an N x N board such that no two queens attack each other. Return all distinct solutions.

# Approach
## Backtracking with Column and Diagonal Sets
One queen per row (guaranteed). For each row, try each column. Skip if column or either diagonal is occupied. Place, recurse to next row, unplace.

Diagonal insight: all cells on the same positive diagonal share `row+col`. All cells on the same negative diagonal share `row-col`. Store these values in sets for O(log n) conflict check without scanning the board.

Traps:
- Use `row-j` (with sign), not `abs(row-j)`. Queens at different positions can have same abs value but are on different diagonals.
- Insert and erase must use the same expression — mismatch causes ghost conflicts.
- `set` uses `erase`, not `remove`.
- Board is `vector<char>` so use `'Q'` and `'.'` (single quotes), not `"Q"`.

### Code
```cpp
void solve(vector<vector<string>>& ans, vector<vector<char>>& board,
           int row, vector<bool>& cols, set<int>& pos, set<int>& neg) {
    if (row == board.size()) {
        vector<string> sa;
        for (int i = 0; i < board.size(); i++) {
            string s(board[i].begin(), board[i].end());
            sa.push_back(s);
        }
        ans.push_back(sa);
        return;
    }
    for (int j = 0; j < board[row].size(); j++) {
        if (cols[j] || pos.count(row+j) || neg.count(row-j)) continue;
        board[row][j] = 'Q';
        pos.insert(row+j); neg.insert(row-j); cols[j] = true;
        solve(ans, board, row+1, cols, pos, neg);
        board[row][j] = '.';
        pos.erase(row+j); neg.erase(row-j); cols[j] = false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<bool> cols(n, false);
    set<int> pos, neg;
    solve(ans, board, 0, cols, pos, neg);
    return ans;
}
```

### Complexity
- Time: $O(N!)$
- Space: $O(N)$ recursion depth + sets
