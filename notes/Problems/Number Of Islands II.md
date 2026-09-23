---
link: https://www.geeksforgeeks.org/problems/number-of-islands/1
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Disjoint Set Union]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "DSU, each new land is +1 island, -1 for every distinct neighbouring set merged"
time: "O(k * α(nm))"
space: "O(n * m)"
date: 
---

# Problem
Turn cells into land one by one, report the island count after each.

# Approach
## DSU
Skip if already land. Else `count++`, then for each land neighbour in a different set, union and `count--`. See [[Disjoint Set Union]].

### Code
```cpp
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DSU dsu(n*m);
        int k = operators.size();
        vector<int> ans;
        vector<int> grid(n*m, 0);
        int count = 0;

        for(auto arr : operators){
            int y = arr[0];
            int x = arr[1];
            int coord = x + y*m;
            if(grid[coord]){
                ans.push_back(count);
                continue;
            }

            grid[coord] = 1;
            count++;

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};

            for(int i = 0; i < 4; i++){
                int adjx = x + dx[i];
                int adjy = y + dy[i];
                if(adjx >= 0 && adjy >= 0 && adjx < m && adjy < n && grid[adjy*m + adjx] == 1){
                    if(dsu.findUPar(coord) != dsu.findUPar(adjy*m + adjx)){
                        count--;
                        dsu.unionBySize(coord, adjy*m + adjx);
                    }
                }
            }
            ans.push_back(count);
        }

        return ans;
    }
```

### Complexity
- Time: $O(k \cdot \alpha(nm))$
- Space: $O(n \cdot m)$
