---
type: reference
topic: Matrix
---

# Matrix

2D grid problems. Common patterns: 4-directional / 8-directional traversal, BFS/DFS on grid, island counting, flood fill.

## When to Use

- Island / region counting
- Shortest path in grid
- Flood fill
- Spiral / rotation

## Template

```cpp
// 4-directional traversal
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool valid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// BFS on grid
void bfs_grid(vector<vector<int>>& grid, int sr, int sc) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    queue<pair<int,int>> q;
    q.push({sr, sc}); vis[sr][sc] = true;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d], nc = c + dy[d];
            if (valid(nr, nc, rows, cols) && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "Matrix")
sort difficulty asc, file.name asc
```
