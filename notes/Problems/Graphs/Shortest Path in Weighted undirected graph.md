---
difficulty: Easy
topics: ["Graphs", "Dijkstra"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1"
---

[[Graphs]] [[Dijkstra]]

# Problem
Find the shortest path from 1 to n

# Solution
We use a tweaked version of [[Dijkstra's Algorithm]] where we also maintain a parents array

```cpp
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    vector<int> dist(n+1, 1e9);
    vector<int> parent(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> path;
    vector<pair<int, int>> adj[n+1];
    
    for(auto i : edges){
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    
    dist[1] = 0;
    pq.push({0, 1});
    parent[1] = 1;
    while(!pq.empty()){
        int wt = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        for(auto i : adj[v]){
            if(dist[i.first] > wt + i.second){
                dist[i.first] = i.second + wt;
                pq.push({dist[i.first], i.first});
                parent[i.first] = v;
            }
        }
    }
    if(dist[n] == 1e9) return {-1};
    int curr = n;
    while(parent[curr] != curr){
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}
```