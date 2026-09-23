---
link: https://leetcode.com/problems/n-queens/
difficulty: Hard
topics:
  - "[[Backtracking]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "same diagonal shares row+col or row-col, keep sets for cols and both diagonals"
time: "O(N!)"
space: "O(N)"
date: 2026-07-01
---

# Problem
Place `n` queens so none attack each other. Return all boards.

# Approach
## Backtracking with Sets
One queen per row, try each column. Same diagonal = same `row+col` or same `row-col`. Keep `cols`, `pos` and `neg` sets.

Traps:
- `row-j` with sign, not `abs`.
- Insert and erase the same expression.
- `vector<char>` board, use `'Q'` not `"Q"`.

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
- Time: $O(n!)$
- Space: $O(n)$
