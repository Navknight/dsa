---
link: https://leetcode.com/problems/number-of-provinces/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[DFS]]"
  - "[[Disjoint Set Union]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "count DFS starts over the adjacency matrix, or n minus successful unions"
time: "O(n²)"
space: "O(n)"
date: 
---

# Problem
Count connected groups of cities from an adjacency matrix.

# Approach
## DFS
Like [[Number Of Islands]]. Each unvisited city starts a new province.

### Code
```cpp
void dfs(vector<vector<int>> &isConnected, int node, vector<bool> &visited){
    visited[node] = true;
    for(int i = 0; i < isConnected.size(); i++){
        if(isConnected[node][i] && !visited[i]){
                dfs(isConnected, i, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, 0);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            count++;
            dfs(isConnected, i, visited);
        }
    }

    return count;
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$

## DSU
Start with `n`, every union of two different sets is `-1`. See [[Disjoint Set Union]].

### Code
```cpp
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DSU dsu(n);
    int count = n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(isConnected[i][j] == 1){
                if(dsu.findUPar(i) != dsu.findUPar(j)){
                    count--;
                    dsu.join(i, j);
                }
            } 
        }
    }

    return count;
}
```

### Complexity
- Time: $O(n^2 \alpha(n))$
- Space: $O(n)$
