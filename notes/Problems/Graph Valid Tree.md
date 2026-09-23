---
link: https://leetcode.com/problems/graph-valid-tree/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Disjoint Set Union]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "tree iff edges == n - 1 and no cycle. DSU finds the cycle"
time: "O(n * α(n))"
space: "O(n)"
date: 2026-08-22
---

# Problem
Do `n` nodes and these undirected edges form a valid tree?

# Approach
## DSU
Tree = `n - 1` edges and no cycle, connectivity then follows. Union each edge with [[Disjoint Set Union]], same root already = cycle.

Mistakes I made:
- Never sized `rank`, out-of-bounds UB.
- Compared `parent[a]` with `parent[b]` instead of `find(a)`, `find(b)`. Breaks once trees merge.

### Code
```cpp
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) return find(parent, parent[x]);
        return parent[x];
    }

    bool detectandunite(vector<int>& parent, vector<int>& rank, int a, int b) {
        int x = find(parent, a), y = find(parent, b);
        if (x == y) return true;

        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<int> parent, rank;
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for (auto e : edges) {
            int a = e[0], b = e[1];
            if (detectandunite(parent, rank, a, b)) return false;
        }

        return true;
    }
};
```

### Complexity
- Time: $O(n \cdot \alpha(n))$
- Space: $O(n)$
