---
link: https://leetcode.com/problems/n-queens/
difficulty: Hard
topics:
  - "[[Backtracking]]"
source: Leetcode
star: true
blind75: false
mastery: yellow
review: 2026-11-13
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

## Scan Earlier Queens
`cols` is a vector with one column per placed row, so the current row is `cols.size()`. A candidate `(r, i)` clashes with queen `j` at `(j, cols[j])` if `i == cols[j]` or `abs(r - j) == abs(i - cols[j])`. No sets to undo, only `pop_back`.

- Checking takes `O(n)` per cell, so about `O(n! * n)`
- `return` after recording a board. Without it the loop still runs and skips everything only because every column is used

### Mistakes
- Called `search(n, r + 1, cols)` while `r` is derived from `cols.size()`, wrong arity
- Base case returned without recording the board, no place to put the answer
- Missing `return` at the leaf

### Code
```cpp
class Solution {
   public:
    void search(int n, vector<int>& cols, vector<vector<string>>& ans) {
        int r = cols.size();
        if (r == n) {
            vector<string> sol;
            for (int i = 0; i < n; i++) {
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (j == cols[i])
                        s += 'Q';
                    else
                        s += '.';
                }
                sol.push_back(s);
            }

            ans.push_back(sol);
        }

        for (int i = 0; i < n; i++) {
            bool skip = false;
            for (int j = 0; j < cols.size(); j++) {
                if (i == cols[j]) {
                    skip = true;
                    break;
                }
                if (i == cols[j] + r - j || i == cols[j] - (r - j)) {
                    skip = true;
                    break;
                }
            }

            if (skip) continue;

            cols.push_back(i);
            search(n, cols, ans);
            cols.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols;

        vector<vector<string>> ans;

        search(n, cols, ans);

        return ans;
    }
};
```

### Complexity
- Time: $O(n! \cdot n)$
- Space: $O(n)$

## Marker Arrays
`colUsed[c]`, `diag1[r + c]`, `diag2[r - c + n - 1]`. The check is three lookups, so about `O(n!)`. Clear all three after the recursive call. Bitmasks do the same in three integers with `x & -x` to pick a free column.

### Code
```cpp
class Solution {
   public:
    vector<bool> colUsed, diag1, diag2;
    vector<int> cols;
    vector<vector<string>> ans;

    void search(int r, int n) {
        if (r == n) {
            vector<string> sol(n, string(n, '.'));
            for (int i = 0; i < n; i++) sol[i][cols[i]] = 'Q';
            ans.push_back(sol);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (colUsed[c] || diag1[r + c] || diag2[r - c + n - 1]) continue;

            colUsed[c] = diag1[r + c] = diag2[r - c + n - 1] = true;
            cols.push_back(c);
            search(r + 1, n);
            cols.pop_back();
            colUsed[c] = diag1[r + c] = diag2[r - c + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        colUsed.assign(n, false);
        diag1.assign(2 * n - 1, false);
        diag2.assign(2 * n - 1, false);
        search(0, n);
        return ans;
    }
};
```

### Complexity
- Time: $O(n!)$
- Space: $O(n)$
