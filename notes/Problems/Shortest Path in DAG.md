---
link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Topological Sort]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "topo sort, then relax edges in topo order"
time: "O(V + E)"
space: "O(V + E)"
date: 
---

# Problem
Shortest distance from node 0 in a weighted DAG, -1 if unreachable.

# Approach
## Topo Order Relaxation
[[Topological Sort]] with DFS, then pop in order and relax each node's edges. Every node is final when popped.

### Code
```cpp
void topoSort(int node, vector<vector<pair<int, int>>> &graph, vector<bool> &vis, stack<int> &s)
{
    vis[node] = true;
    for (auto i : graph[node])
    {
        int v = i.first;
        if (!vis[v])
            topoSort(v, graph, vis, s);
    }
    s.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>());

    for (int i = 0; i < M; i++)
    {
        graph[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
    }

    stack<int> s;
    vector<bool> vis(N);
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topoSort(i, graph, vis, s);
        }
    }

    vector<int> distance(N, 1e9);
    distance[0] = 0;
    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        for (auto i : graph[curr])
        {
            int v = i.first;
            int wt = i.second;
            if (distance[v] > distance[curr] + wt)
            {
                distance[v] = distance[curr] + wt;
            }
        }
    }

    for(int i = 0; i < N; i++)
        if(distance[i] == 1e9)
            distance[i] = -1;

    return distance;
}
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V + E)$
