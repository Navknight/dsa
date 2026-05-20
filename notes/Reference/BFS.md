---
type: reference
topic: BFS
---

# BFS

Breadth-First Search — explores level by level. Guarantees shortest path in unweighted graphs.

## When to Use

- Shortest path (unweighted)
- Level-order traversal
- Multi-source shortest path
- 0-1 BFS (deque)

## Template

```cpp
// BFS on graph
void bfs(int start, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int nb : adj[node]) {
            if (dist[nb] == -1) {
                dist[nb] = dist[node] + 1;
                q.push(nb);
            }
        }
    }
}
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "BFS")
sort difficulty asc, file.name asc
```
