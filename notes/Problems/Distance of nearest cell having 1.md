---
link: https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
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
insight: "multi-source BFS from all 1s at once"
time: "O(m * n)"
space: "O(m * n)"
date: 
---

# Problem
For each cell, distance to the nearest 1.

# Approach
## Multi-Source BFS
Same as [[Rotten Oranges]]. Push every 1 with distance 0, BFS outward.

### Code
```cpp
vector<vector<int>>nearest(vector<vector<int>>grid)
{
    // Code here
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> ans(m, vector<int> (n));
    vector<vector<bool>> visited(m, vector<bool> (n, 0));

    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1){
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        ans[x][y] = dist;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(abs(i) == abs(j))
                    continue;
                if(x+i >= grid.size() || y+j >= grid[0].size() || x+i < 0 || y+j < 0)
                    continue;
                if(!visited[x +i][y+j]){
                    visited[x+i][y+j] = true;
                    q.push({{x+i, y+j}, dist+1});
                }
            }
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
