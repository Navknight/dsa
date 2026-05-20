---
difficulty: Medium
topics: ["Graphs", "Matrix", "BFS"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1"
---

[[Graphs]] [[Matrix]] [[BFS]]

# Problem 
Given a binary grid of **n*m**. Find the distance of the nearest 1 in the grid for each cell.  
The distance is calculated as **|i1  - i2| + |j1 - j2|**, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.

# Solution
This problem is almost exactly the same as the [[Rotten Oranges]] problem, except here we replace time with distance.

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