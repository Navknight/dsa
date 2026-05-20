---
difficulty: Medium
topics: ["Graphs", "Disjoint Set Union"]
source: Standard
star: false
---

[[Graphs]] [[Disjoint Set Union]]

# Problem
You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.

You can change at most one cell in grid from 0 to 1.

You need to find the largest group of connected  1's.

Two cells are said to be connected if both are adjacent to each other and both have same value.

# Solution
This problem is majorly just implementation and brute force use of the [[Disjoint Set Union]]. Here we flip all the zeroes and check if the resulting component is the largest or not.
We need to take care of duplicates as a zero can be surrounded by just one component so when checking the components in the 4 directions around
the zero we need to remember what components we have encountered so far, for that we can use the set data structure to keep track of the ultimate parent of each encountered 1 around the zero  

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

