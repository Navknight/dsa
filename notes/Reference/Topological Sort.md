---
type: reference
topic: Topological Sort
---

# Topological Sort

Linear ordering of DAG vertices. Two approaches: DFS-based or Kahn's (BFS-based). Detects cycles.

## When to Use

- Task scheduling
- Build order / dependency resolution
- Course prerequisites

## Template

```cpp
// Kahn's Algorithm (BFS-based)
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) indegree[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    return order.size() == n ? order : {}; // empty = cycle
}

// DFS-based
void dfsTopo(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfsTopo(v, adj, vis, st);
    st.push(u);
}
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "Topological Sort")
sort difficulty asc, file.name asc
```
