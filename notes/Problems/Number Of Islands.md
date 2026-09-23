---
link: https://leetcode.com/problems/number-of-islands/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
  - "[[DFS]]"
  - "[[Arrays]]"
source: Standard
star: true
blind75: true
mastery:
review:
insight: "DFS flood fill from every unvisited 1, count the starts"
time: "O(m * n)"
space: "O(m * n)"
date: 
---

# Problem
Count islands of `'1'`s.

# Approach
## DFS
Each unvisited `'1'` starts a new island, flood it. BFS works too.

### Code
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

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
