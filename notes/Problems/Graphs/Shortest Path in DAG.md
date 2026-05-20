---
difficulty: Medium
topics: ["Graphs", "Topological Sort"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1"
---

[[Graphs]] [[Topological Sort]]

# Problem
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges\[]\[] of length M, where there is a directed edge from edge\[i]\[0] to edge\[i]\[1] with a distance of edge\[i]\[2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

# Solution
We do a [[Topological Sort]] on the graph and obtain an ordering, then we find the minimum distance
The Topological sort gives a sort of numbering we should follow while finding the minimum distance

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