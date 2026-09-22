---
difficulty: Medium
topics:
  - Graphs
  - Dijkstra
source: Leetcode
star: false
link: https://leetcode.com/problems/network-delay-time/description/
date: 2026-09-22
---
[[Dijkstra]] [[Graphs]]
# Problem
Given a Directed Graph with weights (times), find how much time it'll take for a message to go from node _k_ to all the nodes. -1 if it can't reach all nodes
# Approach
## Dijkstra
The times are just the weights of each edge. Since time cannot be negative, we have a shortest path problem with positive weights. We can use the Dijkstra algorithm directly. Keeping a distance array, we update the distance of each new node from the original `k` node and in the end if any node is at infinity (`INT_MAX`) then that node is unreachable and the answer is -1. 
We need to take the max of all the distance as we need to reach all nodes, Dijkstra takes care of that distance being the minimum for that particular node from `k`.
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
