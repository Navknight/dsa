---
difficulty: Medium
topics: ["Graphs", "Matrix", "DFS", "BFS"]
source: Standard
star: false
link: "https://leetcode.com/problems/surrounded-regions/"
---

[[Graphs]] [[Matrix]] [[DFS]] [[BFS]]

# Problem
Given an `m x n` matrix `board` containing `'X'` and `'O'`, _capture all regions that are 4-directionally surrounded by_ `'X'`.

A region is **captured** by flipping all `'O'`s into `'X'`s in that surrounded region.

# Solution
The idea is that any cluster of O that contains an O which is at the boundary will survive, rest will get converted to X
```cpp
void dfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited){
    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return;
    if(board[i][j] == 'X')
        return;
    if(!visited[i][j]){
        visited[i][j] = true;
        dfs(i+1, j, board, visited);
        dfs(i-1, j, board, visited);
        dfs(i, j+1, board, visited);
        dfs(i, j-1, board, visited);
    }    
    
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));

    for(int i = 0; i < m; i++){
        if(board[i][0] == 'O' && !visited[i][0]){
            dfs(i, 0, board, visited);
        }
    }

    for(int j = 0; j < n; j++){
        if(board[0][j] == 'O' && !visited[0][j])
            dfs(0, j, board, visited);
    }
    for(int i = 0; i < m; i++){
        if(board[i][n-1] == 'O' && !visited[i][n-1]){
            dfs(i, n-1, board, visited);
        }
    }

    for(int j = 0; j < n; j++){
        if(board[m-1][j] == 'O' && !visited[m-1][j])
            dfs(m-1, j, board, visited);
    }


    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == true)
                board[i][j] = 'O';
            else
                board[i][j] = 'X';
        }
    }
}
```