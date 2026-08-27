---
difficulty: Medium
topics:
  - Graphs
  - BFS
source: Leetcode
star: false
link: https://neetcode.io/problems/islands-and-treasure/question?list=neetcode150
date: 2026-08-27
---

[[Graphs]] [[BFS]]

# Problem
Given an `m x n` grid where each cell is `-1` (water/wall), `0` (treasure chest), or `INF` (land), fill every land cell with its distance to the nearest treasure chest. Cells stay `-1` if unreachable.

# Approach
## Multi-Source BFS
Push all treasure cells into the queue up front, each at distance 0, instead of running a separate BFS/DFS per treasure. Because BFS expands level by level, the first time a cell is reached is guaranteed to be via the shortest path from its nearest source — no revisiting or relaxation needed. Use the grid itself as the visited/distance array: only enqueue a neighbor if a shorter distance was actually found (`grid[nx][ny] > grid[x][y] + 1`). Walls are skipped for free since `-1` is never greater than a non-negative distance.

### Code
```cpp
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) q.push({i, j});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] > grid[x][y] + 1) {
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
};
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
