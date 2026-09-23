---
link: https://leetcode.com/problems/detect-cycles-in-2d-grid/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Arrays]]"
  - "[[BFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "BFS per same-char region with parent cell, visited neighbour that isn't the parent = cycle"
time: "O(m * n)"
space: "O(m * n)"
date: 
---

# Problem
Find a cycle of length >= 4 of the same character in a grid, no immediate backtracking.

# Approach
## BFS with Parent
Same as [[Detect cycle in Undirected graph]] but only move to cells with the same char. Carry the parent cell, a visited neighbour that isn't the parent is a cycle.

### Code
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

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
