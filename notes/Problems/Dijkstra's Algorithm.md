---
link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Dijkstra]]"
  - "[[Heap]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "min pq of {dist, node}, push on relax. no negative edges"
time: "O(E log V)"
space: "O(V)"
date: 
---

# Problem
Single source shortest path. No negative edges.

# Approach
## Priority Queue
Min heap of `{dist, node}`. Relax neighbours, push when a distance improves.

### Code
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

### Complexity
- Time: $O(E \log V)$
- Space: $O(V)$

## Set
Same, but a set lets you erase the stale entry.

### Code
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

### Complexity
- Time: $O(E \log V)$
- Space: $O(V)$
