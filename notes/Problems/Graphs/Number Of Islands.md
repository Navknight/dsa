---
difficulty: Medium
topics: ["Graphs", "BFS", "DFS", "Matrix"]
source: Standard
star: false
link: "https://leetcode.com/problems/number-of-islands/"
---

[[Graphs]] [[BFS]] [[DFS]] [[Matrix]]

# Problem
Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return _the number of islands_.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

# Solution
Simple dfs solution, can be done using BFS too

```cpp
void dfs(int i, int j, vector<vector<char >> &grid, vector<vector<bool>> &visited){
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() )
        return;
    if(visited[i][j] == true)
        return;
    if(grid[i][j] == '0')
        return;
    visited[i][j] = true;
    dfs(i-1, j, grid, visited);
    dfs(i, j-1, grid, visited);
    dfs(i+1, j, grid, visited);
    dfs(i, j+1, grid, visited);        
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                count++;
                dfs(i, j, grid, visited);
            }
        }
    }
    return count;
}
```