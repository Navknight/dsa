---
difficulty: Hard
topics: ["Graphs", "Matrix", "DFS"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands"
---

[[Graphs]] [[Matrix]] [[DFS]]

# Problem
Given a boolean 2D matrix **grid** of size **n** * **m**. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

# Solution
This problem is similar to the [[Number Of Islands]] problem, except here we need to maintain a set to store all the islands so that it automatically eliminates the copies.
To get the copies to be equal in value, we subtract the coordinates of the first discovered node from the rest of the nodes.

```cpp
void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &visited, vector<pair<int, int>>& vec, int basei, int basej){
    visited[i][j] = 1;
    vec.push_back({i-basei, j-basej});
    
    for(int a = -1; a <= 1; a++){
        for(int b = -1; b <= 1; b++){
            if(abs(a) == abs(b))
                continue;
            int ni = i + a;
            int nj = j + b;
            
            if(ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && !visited[ni][nj] && grid[ni][nj] == 1)
                dfs(ni, nj, grid, visited, vec, basei, basej);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    // code here
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool> (n, 0));
    set<vector<pair<int,int>>> st;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                if(grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, visited, vec, i, j);
                    st.insert(vec);
                }
            }
        }
    }
    
    return st.size();
}
```