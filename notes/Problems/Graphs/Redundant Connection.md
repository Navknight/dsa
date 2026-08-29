---
difficulty: Medium
topics:
  - Graphs
  - DSU
source: Leetcode
star: false
link: https://leetcode.com/problems/redundant-connection/
date: 2026-08-29
---

[[Graphs]] [[DSU]]

# Problem
Given `n` edges forming a graph with `n` nodes (labeled `1..n`) that had one extra edge added to a tree, return the edge that can be removed to make it a tree again.

# Approach
## Union-Find
A tree with one extra edge has exactly one cycle. Union edges in order; the first edge whose endpoints are already connected closes that cycle, so it's the answer.

Nodes are 1-indexed, so DSU needs size `n + 1`.

### Code
```cpp
class Solution {
public:
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) : parent(n), rank(n) { iota(parent.begin(), parent.end(), 0); }

        int find(int x) {
            if (parent[x] != x) return parent[x] = find(parent[x]);
            return x;
        }

        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if (rank[y] == rank[x]) rank[x]++;
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1);

        for (auto& edge : edges)
            if (!dsu.unite(edge[0], edge[1])) return edge;

        return vector<int>();
    }
};
```

### Complexity
- Time: $O(n \cdot \alpha(n))$
- Space: $O(n)$
