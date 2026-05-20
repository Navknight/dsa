---
type: reference
topic: Disjoint Set Union
---

# Disjoint Set Union

Union-Find data structure. Tracks connected components. O(α(n)) per operation with path compression + union by rank.

## When to Use

- Connected components
- Detect cycle in undirected graph
- Kruskal's MST
- Dynamic connectivity

## Template

```cpp
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
};
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "Disjoint Set Union")
sort difficulty asc, file.name asc
```
