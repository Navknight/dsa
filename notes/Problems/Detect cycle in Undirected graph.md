---
link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
difficulty: Easy
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
  - "[[DFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "BFS/DFS carrying the parent, visited neighbour that isn't the parent = cycle"
time: "O(V + E)"
space: "O(V)"
date: 
---

# Problem
Check if an undirected graph has a cycle.

# Approach
## BFS with Parent
Push `{node, parent}`. A visited neighbour that isn't the parent means a cycle. Run from every unvisited node, the graph may be disconnected.

### Code
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

### Complexity
- Time: $O(V + E)$
- Space: $O(V)$
