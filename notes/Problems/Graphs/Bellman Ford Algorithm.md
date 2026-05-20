---
difficulty: Medium
topics: ["Graphs", "Bellman Ford"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1"
---

[[Graphs]] [[Bellman Ford]] [[Graphs]]

# Problem
Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S. If a vertices can't be reach from the S then mark the distance as 10^8. Note: If the Graph contains a negative cycle then return an array consisting of only -1.

# Solution
Since the graphs can have a negative edge cycle, [[Dijkstra's Algorithm]] will not work as for every iteration the negative cycle will keep on reducing the distance and the queue will not become empty.
So we do exactly `N-1` number of iterations on the graph, and if on the `Nth` iteration the value of distance for a node changes we report that the graph has a negative edge cycle.

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