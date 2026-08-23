---
difficulty: Medium
topics:
  - Graphs
  - DSU
source: Standard
star: false
link: https://neetcode.io/problems/valid-tree/
date: 2026-08-22
---

[[Graphs]] [[DSU]] [[Disjoint Set Union]]

# Problem
Given `n` nodes labeled `0` to `n-1` and a list of undirected edges, determine whether they form a valid tree.

# Approach
## Union-Find (DSU)
A tree on `n` nodes has exactly `n - 1` edges. For any undirected forest (acyclic graph) with `n` nodes and `k` connected components, edge count is always exactly `n - k` (each component with `m` nodes contributes `m - 1` edges). So if the graph is acyclic *and* has exactly `n - 1` edges, that forces `k = 1` — connectivity comes for free, no separate check needed. The two conditions to verify: `edges.size() == n - 1`, and no cycle forms while adding edges.

Use DSU (see [[Disjoint Set Union]]) to detect the cycle in one pass: process edges one at a time, and if two endpoints already share a root, adding this edge would create a cycle. Union by rank keeps `find` near $O(\alpha(n))$.

Bugs hit along the way, worth remembering:
- First attempt declared `rank` but never sized it (`vector<int> parent, rank;` followed by only resizing `parent`). Every `rank[x]` access in the union step was an out-of-bounds read on an empty vector — undefined behavior, would crash or read garbage before the actual logic even ran. Needs `rank = vector<int>(n, 0);` alongside `parent`.
- Second attempt compared `parent[a]`/`parent[b]` directly instead of resolving through `find(a)`/`find(b)` — a `find` function existed in the class but was never called. This conflates "direct parent" with "root," which works by coincidence when every node is at most one hop from its root, but breaks once two multi-node trees merge with each other (some nodes end up two-plus hops from the new root). Concrete failure traced on `n=6, edges=[[0,1],[2,3],[1,2],[3,1],[4,5]]`: after merging `{0,1}` and `{2,3}` via `[1,2]`, node `3`'s direct parent is still `2` (stale, true root is `0`). The redundant edge `[3,1]` should be caught as a cycle (`3` and `1` are already connected), but comparing raw `parent[3]=2` against `parent[1]=0` looks like two different sets, so the cycle is missed — the graph (which is actually disconnected, `{4,5}` never joins the rest) gets wrongly accepted as a valid tree.

Note: `find` still doesn't do path compression (`return find(parent, parent[x])` instead of `parent[x] = find(parent, parent[x])`). Not a correctness issue here since union by rank alone keeps trees shallow (`O(log n)` height), just a missed performance optimization on top of what's already correct.

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
- Time: $O(n \cdot \alpha(n))$ — near-constant per union thanks to union by rank
- Space: $O(n)$ for `parent` and `rank`
