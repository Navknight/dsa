---
link: https://leetcode.com/problems/walls-and-gates/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "multi-source BFS from every treasure, update only if the distance improves"
time: "O(m * n)"
space: "O(m * n)"
date: 2026-08-27
---

# Problem
Fill each land cell with its distance to the nearest treasure.

# Approach
## Multi-Source BFS
Push all treasures at distance 0. Grid is the distance array: enqueue only if `grid[nx][ny] > grid[x][y] + 1`. Walls (-1) never pass that check.

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
