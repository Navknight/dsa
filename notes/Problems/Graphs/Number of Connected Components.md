---
difficulty: Medium
topics:
  - Graphs
  - DFS
source: Standard
star: false
link: https://neetcode.io/problems/count-connected-components/
date: 2026-08-22
---

[[Graphs]] [[DFS]] [[Number Of Provinces]]

# Problem
Given `n` nodes labeled `0` to `n-1` and a list of undirected edges, return the number of connected components in the graph.

# Approach
## Multi-Source DFS
Same shape as [[Number Of Provinces]] — count components by DFS-flooding from every unvisited node. Build an adjacency list from the edge list (bidirectional, since the graph is undirected), then loop over **every node from `0` to `n-1`**: whenever an unvisited node is found, that's a new component, so increment the count and flood-fill from it to mark the whole component visited.

Bug hit along the way: first attempt looped `for (auto e : edges)` instead of over all `n` nodes, and only ever checked `e[0]` as the DFS start point. That misses any node with zero edges entirely — it never appears in the edge list at all, so it's never even considered. Traced on `n=5, edges=[[0,1],[1,2]]`: nodes `3` and `4` have no edges, so the correct answer is `3` components (`{0,1,2}`, `{3}`, `{4}`), but looping over `edges` only ever visits `a` values `0` and `1`, giving `count = 1` — nodes `3` and `4` silently dropped. Looping over all `n` node indices instead of the edge list fixes it, since a node with no edges is still its own (trivial) component.

Also fixed an unrelated sizing detail: `graph`/`vis` were originally sized `n + 1`, but valid node indices only run `0` to `n - 1`, so `n` is correct.

### Code
```cpp
class Solution {
public:
    void dfs(vector<bool>& vis, vector<vector<int>>& graph, int node) {
        if (vis[node]) return;

        vis[node] = true;
        for (auto n : graph[node]) {
            dfs(vis, graph, n);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> vis(n, false);
        int count = 0;
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(vis, graph, i);
            }
        }

        return count;
    }
};
```

### Complexity
- Time: $O(n + e)$ — each node and edge visited once across the whole run
- Space: $O(n + e)$ for the adjacency list, plus $O(n)$ recursion stack
