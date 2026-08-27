---
difficulty: Medium
topics:
  - Graphs
  - DFS
source: Leetcode
star: false
link: https://leetcode.com/problems/max-area-of-island/
date: 2026-08-27
---

[[Graphs]] [[DFS]]

# Problem
Given an `m x n` binary grid, an island is a group of `1`s connected 4-directionally. Return the area of the largest island (0 if none exists).

# Approach
## DFS Flood Fill
Same pattern as Number Of Islands, but instead of just counting components, each DFS call returns the size of the island it just flooded. Track the max across all unvisited land cells.

### Code
```cpp
class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
        if (vis[i][j] || grid[i][j] == 0) return 0;

        vis[i][j] = true;
        return 1 + dfs(grid, vis, i-1, j) + dfs(grid, vis, i+1, j)
                  + dfs(grid, vis, i, j-1) + dfs(grid, vis, i, j+1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!vis[i][j] && grid[i][j] == 1)
                    ans = max(ans, dfs(grid, vis, i, j));

        return ans;
    }
};
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
