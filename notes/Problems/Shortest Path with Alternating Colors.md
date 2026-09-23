---
link: https://leetcode.com/problems/shortest-path-with-alternating-colors/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "BFS on (node, last color), run starting with red and with blue"
time: "O(V + E)"
space: "O(V + E)"
date: 2024-04-08
---

# Problem
Shortest path from 0 to each node with alternating edge colors.

# Approach
## BFS on (node, color)
Unit weights, so BFS. Alternate red and blue edges. Run once starting red, once starting blue, keep the min.

### Code
```cpp
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<int>> red(n), blue(n);
        for (auto e : redEdges)
        {
            red[e[0]].push_back(e[1]);
        }
        for (auto e : blueEdges)
        {
            blue[e[0]].push_back(e[1]);
        }

        vector<int> dis(n, 1e6);
        dis[0] = 0;

        for (int i = 0; i < 2; i++)
        {
            vector<vector<bool>> vis(n, vector<bool>(2, 0));
            vis[0][i] = 1;
            priority_queue<pair<int, pair<int, bool>>, vector<pair<int, pair<int, bool>>>, greater<pair<int, pair<int, bool>>>> pq;
            pq.push({0, {0, i}});

            vector<vector<int>> edges;

            while (!pq.empty())
            {
                int d = pq.top().first;
                int node = pq.top().second.first;
                bool last = pq.top().second.second;
                pq.pop();

                edges.clear();
                edges = (last) ? blue : red;
                if (edges[node].empty() == false)
                {
                    for (auto v : edges[node])
                    {
                        if (!vis[v][!last])
                        {
                            vis[v][!last] = true;
                            dis[v] = min(dis[v], 1 + d);
                            pq.push({1 + d, {v, !last}});
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (dis[i] == 1e6)
                dis[i] = -1;

        return dis;
    }
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V + E)$
