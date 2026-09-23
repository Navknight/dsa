---
link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Dijkstra]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "Dijkstra with ways[]: shorter resets ways[v] = ways[u], equal adds ways[u]"
time: "O(E log V)"
space: "O(V + E)"
date: 
---

# Problem
Number of shortest paths from `0` to `n-1`, mod 1e9+7.

# Approach
## Dijkstra + Path Counts
[[Dijkstra's Algorithm]] with `ways[]`. Strictly shorter: `ways[v] = ways[u]`. Equal: `ways[v] += ways[u]`. Use `long long`.

### Code
```cpp
#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto& road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        return dijkstra(graph, n, 0);
    }
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); // dist, src
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
```

### Complexity
- Time: $O(E \log V)$
- Space: $O(V + E)$
