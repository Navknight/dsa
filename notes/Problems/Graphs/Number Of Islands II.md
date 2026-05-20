---
difficulty: Medium
topics: ["Graphs", "Disjoint Set Union"]
source: Standard
star: false
---

[[Graphs]] [[Disjoint Set Union]]

# Problem
You are given a **n,m** which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A\[i]\[0], A\[i]\[1] means that you can change the cell matrix\[A\[i]\[0]]\[A\[i]\[1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size **k**.  
**Note :** An island means group of 1s such that they share a common side.


# Solution
We use the [[Disjoint Set Union]] method to keep track of the islands merging. This is a standard implementation of the DSU problem and doesn't require much tweaking

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
