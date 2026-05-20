---
difficulty: Medium
topics:
  - Graphs
  - Dijkstra
source: Standard
star: false
link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
---

[[Graphs]] [[Dijkstra]]

# Problem
Shortest path from single source

# Solution
### Works only when ->
	No negative edges in the graph
### Using Priority Queue
Starting from the source node, update the distances of the other nodes initially set to infinity. If the distance of a node is updated then it is pushed onto the priority queue.

```cpp
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    
    dist[S] = 0;
    pq.push({0, S});
    
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto i : adj[node]){
            int wt = i[1];
            int v = i[0];
            
            if(dist[v] > wt + d){
                dist[v] = wt + d;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
```


### Using Sets
Same logic as Priority Queue

```cpp
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    
    dist[S] = 0;
    st.insert({0, S});
    
    while(!st.empty()){
        auto it = *st.begin();
        int d = it.first;
        int v = it.second;
        st.erase(it);
        
        for(auto i : adj[v]){
            if(dist[i[0]] > d + i[1]){
                dist[i[0]] = d + i[1];
                st.insert({dist[i[0]], i[0]});
            }
        }
    }
    
    return dist;
}
```