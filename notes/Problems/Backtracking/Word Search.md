---
difficulty: Medium
topics: ["Backtracking"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/word-search/description/"
---

[[Backtracking]]

```cpp
    vector<int> dx ={1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool solve(vector<vector<char>>& board, vector<vector<bool>> &vis, int idx, int x, int y, string& word){
        if(idx >= word.size())
            return true;
        if(x >= board.size() || x < 0 || y >= board[0].size() || y < 0) return false;
        if(vis[x][y] || board[x][y] != word[idx]) return false;

        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = dy[i] + y;

            if(solve(board, vis, idx+1, nx, ny, word)) return true;
        }
        vis[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), 0));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && solve(board, vis, 0, i, j, word))
                    return true;
            }
        }

        return false;
    }
```
