---
difficulty: Easy
topics: ["Graphs", "BFS", "Cycle Detection"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/"
---

[[Graphs]] [[BFS]] [[Cycle Detection]]

# Problem
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
# Solution
This question can be solved using both BFS and DFS, i've done it using bfs. So if a vertex is already visited and its not the parent vertex then we have a cycle.

```cpp
bool bfs(int vert, vector<int> adj[], vector<bool> &visited){
    queue<pair<int, int>> q;
    
    q.push({vert, -1});
    visited[vert] = true;
    
    while(!q.empty()){
        int vert = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(int i = 0; i < adj[vert].size(); i++){
            if(visited[adj[vert][i]] && adj[vert][i] != parent){
                return true;
            }
            else{
                if(!visited[adj[vert][i]]){
                    visited[adj[vert][i]] = true;
                    q.push({adj[vert][i], vert});
                }
            }
        }
    }
    
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> visited(V, 0);
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(bfs(i, adj, visited))
                return true;
        }
    }
    
    return false;
}
```