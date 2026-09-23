---
link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[DFS]]"
source: Standard
star: true
blind75: true
mastery:
review:
insight: "loop over all n nodes, DFS from each unvisited one, count starts"
time: "O(n + e)"
space: "O(n + e)"
date: 2026-08-22
---

# Problem
Number of connected components in an undirected graph.

# Approach
## DFS
Same as [[Number Of Provinces]]. Loop over every node `0..n-1`, each unvisited one starts a new component.

Mistake I made: looped over `edges`, so isolated nodes were never counted.

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
- Time: $O(n + e)$
- Space: $O(n + e)$
