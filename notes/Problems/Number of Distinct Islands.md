---
link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
difficulty: Hard
topics:
  - "[[Graphs]]"
  - "[[Arrays]]"
  - "[[DFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "record each island's cells relative to its first cell, put the shapes in a set"
time: "O(m * n log(m * n))"
space: "O(m * n)"
date: 
---

# Problem
Count islands with distinct shapes (no rotation or reflection).

# Approach
## DFS + Set of Shapes
Like [[Number Of Islands]]. Store each cell as an offset from the island's first cell, insert the list into a set.

### Code
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

### Complexity
- Time: $O(m \cdot n \log(m \cdot n))$
- Space: $O(m \cdot n)$
