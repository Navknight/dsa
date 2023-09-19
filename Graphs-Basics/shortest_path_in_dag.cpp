#include <bits/stdc++.h>

using namespace std;

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

    return distance;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges(M);
    for (int i = 0; i < M; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
    }

    vector<int> dist = shortestPath(N, M, edges);
    for (int i = 0; i < N; i++)
    {
        cout << dist[i] << endl;
    }

    return 0;
}