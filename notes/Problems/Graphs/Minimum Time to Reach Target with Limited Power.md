---
difficulty: Hard
topics:
  - Dijkstra
  - Graphs
source: Leetcode
star: false
link: https://leetcode.com/contest/weekly-contest-508/problems/minimum-time-to-reach-target-with-limited-power/
date: 2026-06-28
---

[[Dijkstra]] [[Graphs]]

# Problem
Directed weighted graph. Signal starts at source with given power. Can only traverse edge from node `u` if `remaining_power >= cost[u]`; traversal deducts `cost[u]`. Find minimum time to reach target. Among all min-time paths, return max remaining power.

# Approach
## Dijkstra on `(node, remaining_power)` State

State is `(node, remaining_power)` not just `node`: same node with different power levels can reach different neighbors. State space: $n \times P = 10^6$, manageable.

Priority queue ordered by `(time ASC, -power)`: secondary `-power` ensures first pop of target gives both min time and max remaining power simultaneously.

`dist[node][power]` = min time to reach that state. Skip if stale or `pw < cost[node]`.

# Code
```cpp
vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
    if (source == target) return {0, (long long)power};
    vector<vector<pair<int,int>>> adj(n);
    for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
    vector<vector<long long>> dist(n, vector<long long>(power + 1, LLONG_MAX));
    priority_queue<tuple<long long,int,int,int>,
                   vector<tuple<long long,int,int,int>>,
                   greater<>> pq;
    dist[source][power] = 0;
    pq.push({0, -power, source, power});
    while (!pq.empty()) {
        auto [t, npw, node, pw] = pq.top(); pq.pop();
        if (node == target) return {t, (long long)pw};
        if (t > dist[node][pw]) continue;
        if (pw < cost[node]) continue;
        int newpw = pw - cost[node];
        for (auto [v, w] : adj[node]) {
            long long newt = t + w;
            if (newt < dist[v][newpw]) {
                dist[v][newpw] = newt;
                pq.push({newt, -newpw, v, newpw});
            }
        }
    }
    return {-1, -1};
}
```

# Complexity
- Time: $O((n \cdot P + E) \log(n \cdot P))$ where $P$ = initial power, $E$ = edges
- Space: $O(n \cdot P)$
