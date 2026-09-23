---
link: https://leetcode.com/problems/max-area-of-island/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "DFS returns the island size, track the max"
time: "O(m * n)"
space: "O(m * n)"
date: 2026-08-27
---

# Problem
Area of the largest island.

# Approach
## DFS
[[Number Of Islands]] but each DFS returns the size it flooded.

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
