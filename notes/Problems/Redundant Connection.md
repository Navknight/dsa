---
link: https://leetcode.com/problems/redundant-connection/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Disjoint Set Union]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "union edges in order, the first one whose ends are already connected is the answer"
time: "O(n * α(n))"
space: "O(n)"
date: 2026-08-29
---

# Problem
A tree plus one extra edge. Return the edge to remove.

# Approach
## DSU
First edge whose ends already share a root closes the cycle. Nodes are 1-indexed, size `n + 1`.

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
