---
link: https://leetcode.com/problems/surrounded-regions/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[DFS]]"
  - "[[BFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "flood fill from border O's, everything else that's O gets captured"
time: "O(m * n)"
space: "O(m * n)"
date: 2026-08-29
---

# Problem
Flip every `O` region not touching the border to `X`.

# Approach
Border-connected `O`s survive. Flood from the border, flip the rest.

## DFS with Visited

### Code
```cpp
void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return;
    if (board[i][j] == 'X')
        return;
    if (!visited[i][j]) {
        visited[i][j] = true;
        dfs(i + 1, j, board, visited);
        dfs(i - 1, j, board, visited);
        dfs(i, j + 1, board, visited);
        dfs(i, j - 1, board, visited);
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));

    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O' && !visited[i][0]) dfs(i, 0, board, visited);
        if (board[i][n - 1] == 'O' && !visited[i][n - 1]) dfs(i, n - 1, board, visited);
    }
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O' && !visited[0][j]) dfs(0, j, board, visited);
        if (board[m - 1][j] == 'O' && !visited[m - 1][j]) dfs(m - 1, j, board, visited);
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = visited[i][j] ? 'O' : 'X';
}
```

### Complexity
- Time: $O(mn)$
- Space: $O(mn)$

## DFS with In-Place Marking
Mark survivors as `#`, then `O -> X` and `# -> O`.

### Code
```cpp
void dfs(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
    if (board[i][j] == 'X' || board[i][j] == '#') return;

    board[i][j] = '#';
    dfs(board, i + 1, j);
    dfs(board, i, j + 1);
    dfs(board, i - 1, j);
    dfs(board, i, j - 1);
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < n; i++) {
        if (board[0][i] == 'O') dfs(board, 0, i);
        if (board[m - 1][i] == 'O') dfs(board, m - 1, i);
    }
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') dfs(board, i, 0);
        if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
}
```

### Complexity
- Time: $O(mn)$
- Space: $O(mn)$ stack
