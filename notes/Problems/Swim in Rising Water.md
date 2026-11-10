---
link: https://leetcode.com/problems/swim-in-rising-water/
difficulty: Hard
topics:
  - "[[Graphs]]"
  - "[[Dijkstra]]"
  - "[[Heap]]"
  - "[[Disjoint Set Union]]"
source: Leetcode
star: true
blind75: false
mastery: red
review: 2026-11-11
insight: "path cost is the max cell on it. expand the lowest frontier cell, or add cells in height order and union until the corners connect"
time: "O(n² log n)"
space: "O(n²)"
date: 2026-11-10
---

# Problem
Grid of distinct elevations. Move between adjacent cells once the water level reaches both. Least time to get from the top left to the bottom right.

# Approach
The cost of a path is its highest cell, not a sum. Minimise the max.

## Heap (Dijkstra / Prim)
Min heap keyed by the cell's height. Pop the lowest frontier cell, keep a running `maxHeight` of what was popped, stop when `(n-1, n-1)` pops. It is Dijkstra with `max` instead of `+`.

- Mark visited on push, not pop. The key is the cell's own height, so a cell can't get a better key later and is pushed once

### Mistakes
- Tried a local greedy: step to the smallest neighbour that gets closer to the goal. Fails on `[[0,1,8],[2,7,3],[4,5,6]]`, it takes `0,1,7,3,6` for 7, best is `0,2,4,5,6` for 6. The greedy has to be over the whole frontier, not the neighbours of one cell
- Marked visited on pop, so a cell sat in the heap several times and got re-expanded

### Code
```cpp
class Solution {
   public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        int maxHeight = grid[0][0];

        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            auto curr = pq.top();
            visited[curr.second.first][curr.second.second] = true;
            maxHeight = max(maxHeight, curr.first);
            if (curr.second.first == n - 1 && curr.second.second == n - 1) return maxHeight;
            pq.pop();

            for (int d = 0; d < 4; d++) {
                int nx = dx[d] + curr.second.first;
                int ny = dy[d] + curr.second.second;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }

        return -1;
    }
};
```

### Complexity
- Time: $O(n^2 \log n)$
- Space: $O(n^2)$

## DSU
Heights are a permutation of `0..n²-1`, so each height is its own rank. `pos[h]` = the cell with height `h`. For `t = 0, 1, ...` activate `pos[t]`, union it with active neighbours, stop at the first `t` where the corners share a set. `t` is the answer.

- No heap, no sort. Only works because the heights are a permutation, otherwise sort the cells first
- Only union with neighbours that are already active. The loop activates cells in height order, a taller cell isn't active yet so nothing joins through it early
- A union carries no height. The water level is the loop variable `t`
- Binary search on `t` doesn't help, a DSU only moves forward in time. Rebuilding for each `t` is `O(n²)` again

### Mistakes
- `class DSU` with everything private, add `public:`
- Wrote `i < n*n` in a loop over `t`
- Called `find` and `join` as free functions, they are members
- `new DSU` is never deleted, use a stack object `DSU dsu(n * n);`

### Code
```cpp
class DSU {
    vector<int> parent;

   public:
    int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    void join(int x, int y) { parent[find(x)] = find(y); }

    DSU(int x) {
        parent = vector<int>(x);
        for (int i = 0; i < x; i++) parent[i] = i;
    }
};

class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU* dsu = new DSU(n * n);

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        vector<int> pos(n * n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = i * n + j;
            }
        }

        vector<bool> active(n * n, 0);

        for (int t = 0; t < n * n; t++) {
            int cell = pos[t];
            active[cell] = true;

            int x = cell / n;
            int y = cell % n;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && active[nx * n + ny]) {
                    dsu->join(cell, nx * n + ny);
                }
            }

            if (dsu->find(0) == dsu->find((n - 1) * n + n - 1)) return t;
        }

        return -1;
    }
};
```

### Complexity
- Time: $O(n^2 \alpha(n^2))$
- Space: $O(n^2)$
