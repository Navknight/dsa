---
difficulty: Medium
topics: ["Graphs", "Matrix", "BFS"]
source: Standard
star: false
link: "https://leetcode.com/problems/detect-cycles-in-2d-grid/description/"
---

[[Graphs]] [[Matrix]] [[BFS]]

# Problem
Given a 2D array of characters `grid` of size `m x n`, you need to find if there exists any cycle consisting of the **same value** in `grid`.

A cycle is a path of **length 4 or more** in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the **same value** of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle `(1, 1) -> (1, 2) -> (1, 1)` is invalid because from `(1, 2)` we visited `(1, 1)` which was the last visited cell.

Return `true` if any cycle of the same value exists in `grid`, otherwise, return `false`.

# Solution
Very similar to the [[Detect cycle in Undirected graph]] question, except here the cycles are character specific which makes it a bit tricky.
Solved using BFS, but a DFS Solution should also be possible
```cpp
bool bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j, char ch){
    queue<pair<pair<int, int>,pair<int, int>>> q;
    q.push({{i, j}, {-1,-1}});
    visited[i][j] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;

        int px = q.front().second.first;
        int py = q.front().second.second;
        q.pop();

        for(int a = -1; a<=1; a++){
            for(int b = -1; b<=1; b++){
                if(x+a >= grid.size() || y+b >= grid[0].size() || a+x < 0 || b+y < 0)
                    continue;
                if(grid[x+a][y+b] != ch)
                    continue;
                if(abs(a) == abs(b))
                    continue;
                else{
                    if(!visited[x+a][y+b]){
                        q.push({{x+a, y+b}, {x,y}});
                        visited[x+a][y+b] = true;
                    }
                    else if(px == x+a && py == y+b)
                        continue;
                    else
                        return true;
                }
            }
        }
    }

    return false;
}

bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool> (n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j])
                if(bfs(grid, visited, i, j, grid[i][j]))
                    return true;
        }
    }

    return false;
}
```