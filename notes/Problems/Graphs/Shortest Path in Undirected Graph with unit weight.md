---
difficulty: Easy
topics: ["Graphs", "BFS"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1"
---

[[Graphs]] [[BFS]]

# Problem
You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

# Solution
Run a simple BFS, and update the distance array instead of the visited array.

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