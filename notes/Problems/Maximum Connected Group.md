---
link: https://www.geeksforgeeks.org/problems/maximum-connected-group/1
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Disjoint Set Union]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "DSU the 1s, for each 0 sum the sizes of distinct neighbouring roots + 1"
time: "O(n²)"
space: "O(n²)"
date: 
---

# Problem
Flip at most one 0 to 1 in an `n x n` grid. Largest connected group of 1s.

# Approach
## DSU
Union adjacent 1s with [[Disjoint Set Union]]. For each 0, collect distinct roots of its neighbours in a set, size = 1 + their sizes. Also check the max existing component (no flip).

### Code
```cpp
int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        DSU dsu(n*n);

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0)
                    continue;

                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, -1, 0, 1};
                for(int i = 0; i < 4; i++){
                    int newr = row + dx[i];
                    int newc = col + dy[i];

                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1){
                        int node = row * n + col;
                        int adj = newr * n + newc;
                        dsu.unionBySize(node, adj);
                    }
                }
            }
        }

        int mx = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) 
                    continue;

                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, -1, 0, 1};

                set<int> vis;

                for(int i = 0; i < 4; i++){
                    int newr = row + dx[i];
                    int newc = col + dy[i];

                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1){
                        int node = row * n + col;
                        int adj = newr * n + newc;
                        vis.insert(dsu.findUPar(adj));
                    }
                }

                int sizeTotal = 1;
                for( auto it : vis){
                    sizeTotal += dsu.size[it];
                }

                mx = max(mx, sizeTotal);
            }
        }

        for(int cell = 0; cell < n*n ; cell++)
            mx = max(mx,dsu.size[dsu.findUPar(cell)]);

        return mx;
    }
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n^2)$
