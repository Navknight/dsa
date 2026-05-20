---
type: reference
topic: MST
---

# MST

Minimum Spanning Tree — connects all vertices with minimum total edge weight. Two algorithms: Kruskal (sort edges + DSU) and Prim (greedy + heap).

## When to Use

- Minimum cost network
- Cluster analysis
- Approximation algorithms

## Template

```cpp
// Kruskal's MST
int kruskal(int n, vector<tuple<int,int,int>>& edges) { // {weight, u, v}
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mst_cost = 0;
    for (auto [w, u, v] : edges)
        if (dsu.unite(u, v)) mst_cost += w;
    return mst_cost;
}

// Prim's MST
int prim(int src, vector<vector<pair<int,int>>>& adj, int n) {
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});
    int cost = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true; cost += w;
        for (auto [wt, v] : adj[u])
            if (!inMST[v]) pq.push({wt, v});
    }
    return cost;
}
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "MST")
sort difficulty asc, file.name asc
```
