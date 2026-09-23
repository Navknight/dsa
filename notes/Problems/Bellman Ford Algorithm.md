---
link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
difficulty: Medium
topics:
  - "[[Graphs]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "relax all edges V-1 times, if the Vth pass still relaxes there's a negative cycle"
time: "O(V * E)"
space: "O(V)"
date: 
---

# Problem
Shortest distance from `S` to every vertex with negative weights. Return `{-1}` on a negative cycle.

# Approach
## Bellman Ford
[[Dijkstra's Algorithm]] loops forever on a negative cycle. Relax every edge `V-1` times instead. If one more pass still relaxes an edge, there's a negative cycle.

### Code
```cpp
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Code here
    vector<int> distance(V, 1e8);
    distance[S] = 0;
    for(int i = 0; i < V-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int dis = it[2];

            if(distance[u] != 1e8 && distance[u] + dis < distance[v])
                distance[v] = distance[u] + dis;
        }
    }

    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int dis = it[2];

        if(distance[u] != 1e8 && distance[u] + dis < distance[v])
            return {-1};
    }

    return distance;
}
```

### Complexity
- Time: $O(V \cdot E)$
- Space: $O(V)$
