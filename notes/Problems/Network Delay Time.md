---
link: https://leetcode.com/problems/network-delay-time/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Dijkstra]]"
source: Leetcode
star: false
blind75: false
mastery: yellow
review: 2026-11-11
insight: "Dijkstra from k, answer is the max distance, -1 if any node is unreached"
time: "O((V + E) log V)"
space: "O(V + E)"
date: 2026-09-22
---

# Problem
Time for a signal from `k` to reach every node, or -1.

# Approach
## Dijkstra
Weights are non-negative, plain Dijkstra. Answer is the max of all distances, -1 if any is still infinity.

### Code
```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> gp(n + 1, vector<pair<int, int>>());

        for (auto& t : times)
            gp[t[0]].push_back({t[2], t[1]});

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dis(n + 1, INT_MAX);

        pq.push({0, k});

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            if (dis[node.second] > node.first) {
                dis[node.second] = node.first;
                for (auto& e : gp[node.second]) {
                    pq.push({e.first + node.first, e.second});
                }
            }
        }

        int time = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX)
                return -1;
            time = max(time, dis[i]);
        }

        return time;
    }
};
```

### Complexity
- Time: $O((V+E)\log V)$
- Space: $O(V+E)$

## Bellman-Ford
Fine at n <= 100, no graph and no heap. Guard `dist[u] != INT_MAX` or the sum overflows.

### Code
```cpp
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    for (int round = 0; round < n - 1; round++) {
        bool changed = false;
        for (auto& e : times) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}
```

### Complexity
- Time: $O(V \cdot E)$
- Space: $O(V)$

- Nodes are 1..n. `graph(n + 1)` and scan `dist` from 1, index 0 stays INT_MAX
- Min-heap of `(dist, node)`: `priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>`. A custom comparator returns true when `a` has lower priority, so `a.first > b.first` for a min-heap
- Skip stale entries: `if (time > dist[node]) continue`
- Answer is the max of `dist[1..n]`, -1 if any is INT_MAX
- Push `(0, k)` as the seed, not k's edges

### Mistakes
- Forgot to write `dist[v]` when pushing. Without it the relax test is always true
