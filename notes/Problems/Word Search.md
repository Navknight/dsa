---
link: https://leetcode.com/problems/word-search/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[DFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "DFS from every cell, mark with '#' and restore"
time: "O(m * n * 4^L)"
space: "O(L)"
date: 2026-06-30
---

# Problem
Does `word` exist in the grid via adjacent cells, each used once?

# Approach
## DFS with Visited

### Code
```cpp
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool solve(vector<vector<char>>& board, vector<vector<bool>>& vis, int idx, int x, int y, string& word) {
    if (idx >= word.size()) return true;
    if (x >= board.size() || x < 0 || y >= board[0].size() || y < 0) return false;
    if (vis[x][y] || board[x][y] != word[idx]) return false;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
        if (solve(board, vis, idx+1, x+dx[i], dy[i]+y, word)) return true;
    vis[x][y] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), 0));
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (board[i][j] == word[0] && solve(board, vis, 0, i, j, word))
                return true;
    return false;
}
```

### Complexity
- Time: $O(m \cdot n \cdot 4^L)$
- Space: $O(m \cdot n)$

## DFS with Visited, Start Marked in Caller
Trap: `dy = {0, 0, 1, -1}` paired with `dx = {1, 0, -1, 0}` makes one direction a no-op.

### Code
```cpp
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool solve(vector<vector<char>>& board, vector<vector<bool>>& visited,
           string word, int x, int y, int idx) {
    if (idx == word.size()) return true;
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i], newy = y + dy[i];
        if (newx < 0 || newy < 0 || newx >= board.size() ||
            newy >= board[0].size() || visited[newx][newy] ||
            word[idx] != board[newx][newy]) continue;
        visited[newx][newy] = true;
        if (solve(board, visited, word, newx, newy, idx+1)) return true;
        visited[newx][newy] = false;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (word[0] == board[i][j]) {
                visited[i][j] = true;
                if (solve(board, visited, word, i, j, 1)) return true;
                visited[i][j] = false;
            }
        }
    }
    return false;
}
```

### Complexity
- Time: $O(m \cdot n \cdot 4^L)$
- Space: $O(m \cdot n)$

## Board Marking
Overwrite with `#` and restore, no visited array.

### Code
```cpp
bool solve(vector<vector<char>>& board, string& word, int x, int y, int idx) {
    if (idx == word.size()) return true;
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
    if (board[x][y] != word[idx]) return false;
    char tmp = board[x][y];
    board[x][y] = '#';
    bool found = solve(board, word, x+1, y, idx+1) ||
                 solve(board, word, x-1, y, idx+1) ||
                 solve(board, word, x, y+1, idx+1) ||
                 solve(board, word, x, y-1, idx+1);
    board[x][y] = tmp;
    return found;
}
```

### Complexity
- Time: $O(m \cdot n \cdot 4^L)$
- Space: $O(L)$
