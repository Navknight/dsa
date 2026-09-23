---
link: https://leetcode.com/problems/minimum-time-to-reach-target-with-limited-power/
difficulty: Hard
topics:
  - "[[Dijkstra]]"
  - "[[Graphs]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "Dijkstra on (node, power left), pq by (time, -power) so the first target pop wins both"
time: "O((n * P + E) log(n * P))"
space: "O(n * P)"
date: 2026-06-28
---

# Problem
Directed graph, leaving `u` costs `cost[u]` power. Min time to target, tie-break by max power left.

# Approach
## Dijkstra on (node, power)
Same node with different power reaches different places, so power is part of the state. Order the pq by `(time, -power)`, the first pop of the target is the answer.

### Code
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

### Complexity
- Time: $O((nP + E) \log(nP))$
- Space: $O(nP)$
