---
difficulty: Medium
topics: ["Graphs", "BFS"]
source: Leetcode
star: false
code: LeetCode/Shortest_Path_with_Alternating_Colors.cpp
---
[[LeetCode/Shortest_Path_with_Alternating_Colors.cpp]]
[[Graphs]] [[BFS]]

Link :: [Leetcode](https://leetcode.com/problems/shortest-path-with-alternating-colors/description/?envType=study-plan-v2&envId=graph-theory)
# Problem
You are given an integer `n`, the number of nodes in a directed graph where the nodes are labelled from `0` to `n - 1`. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays `redEdges` and `blueEdges` where:

- `redEdges[i] = [ai, bi]` indicates that there is a directed red edge from node `ai` to node `bi` in the graph, and
- `blueEdges[j] = [uj, vj]` indicates that there is a directed blue edge from node `uj` to node `vj` in the graph.

Return an array `answer` of length `n`, where each `answer[x]` is the length of the shortest path from node `0` to node `x` such that the edge colors alternate along the path, or `-1` if such a path does not exist.

# Solution
This is a simple [[Dijkstra's Algorithm]] (even BFS as all edge weights are 1) on the graph where for each alternate step we choose from a different coloured edge. The whole BFS is run twice, once by considering that the 0th edge was blue and then by considering that it was red.

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

