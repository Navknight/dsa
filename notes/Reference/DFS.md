---
type: reference
topic: DFS
---

# DFS

Depth-First Search — explores as far as possible before backtracking. Uses recursion or explicit stack.

## When to Use

- Detect cycles
- Topological sort
- Connected components
- Path existence
- Tree traversals

## Template

```cpp
// Recursive DFS on graph
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

// Iterative DFS
void dfs_iter(int start, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (int nb : adj[node]) st.push(nb);
    }
}
```

## Problems

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "DFS")
sort difficulty asc, file.name asc
```
