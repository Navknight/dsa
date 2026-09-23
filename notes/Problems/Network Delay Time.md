---
link: https://leetcode.com/problems/network-delay-time/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Dijkstra]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
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
