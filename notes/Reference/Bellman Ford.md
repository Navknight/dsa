---
type: reference
topic: Bellman Ford
---

# Bellman Ford

Single-source shortest path. O(VE). Handles negative edges. Detects negative cycles.

## When to Use

- Negative weight edges
- Detect negative cycles
- Arbitrage detection

## Template

```cpp
// Bellman-Ford
vector<int> bellmanFord(int src, vector<tuple<int,int,int>>& edges, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
    // Check negative cycle
    for (auto [u, v, w] : edges)
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            return {}; // negative cycle exists
    return dist;
}
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "Bellman Ford")
sort difficulty asc, file.name asc
```
