---
type: reference
topic: Dijkstra
---

# Dijkstra

Single-source shortest path for non-negative weighted graphs. O((V+E) log V) with priority queue.

## When to Use

- Shortest path with weights
- Minimum cost path
- Network routing

## Template

```cpp
// Dijkstra with min-heap
vector<int> dijkstra(int src, vector<vector<pair<int,int>>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

## Problems

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "Dijkstra")
sort difficulty asc, file.name asc
```
