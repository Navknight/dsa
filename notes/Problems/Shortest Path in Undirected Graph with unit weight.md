---
link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
difficulty: Easy
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "BFS with a dist array instead of visited"
time: "O(V + E)"
space: "O(V + E)"
date: 
---

# Problem
Shortest distance from `src` with unit weights.

# Approach
## BFS
Update `dist[v] = dist[u] + 1` when it improves.

### Code
```cpp
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // code here
    vector<vector<int>> graph(N, vector<int> ());
    for(int i = 0; i < M; i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> dist(N, 1e9);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(auto i : graph[curr]){
            if(dist[i] > dist[curr] + 1){
                dist[i] = dist[curr] + 1;
                q.push(i);
            }
        }
    }

    for(int i = 0; i <N; i++)
        if(dist[i] == 1e9)
            dist[i] = -1;

    return dist;
}
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V + E)$
