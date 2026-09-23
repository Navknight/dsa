---
link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
difficulty: Medium
topics:
  - "[[Graphs]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "for each k, dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]). negative diagonal = negative cycle"
time: "O(n³)"
space: "O(1)"
date: 
---

# Problem
All-pairs shortest paths on an adjacency matrix, in place. `-1` = no edge.

# Approach
## Floyd Warshall
Try every node `k` as a middle stop for every pair. `-1` to `1e9` before, back after.

### Code
```cpp
void shortest_distance(vector<vector<int>>&matrix){
    // Code here
    int n = matrix.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == -1)
                matrix[i][j] = 1e9;

        if(i == j)
            matrix[i][j] = 0;
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}
```

### Complexity
- Time: $O(n^3)$
- Space: $O(1)$

## Negative Cycle
Any `dist[i][i] < 0` afterwards means a negative cycle.

### Code
```cpp
for(int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        if(matrix[i][j] < 0)
            return 1;
    }
}
```
