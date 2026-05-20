---
difficulty: Medium
topics: ["Graphs", "MST"]
source: Standard
star: false
---

[[Graphs]] [[MST]] [[MST]] [[MST]]

#DSA-Theory 
### Spanning tree ->
A graph is a connected subgraph with all the vertices but no cycles.

### Mimimum ->
A spanning tree which has the minimum sum of all the edge weights

### Prim's Algorithm
We start with any node and add the edge incident onto it with the smallest weight to the MST along with the node attached to that edge. We then find the edge with the smallest edge weight in the new cluster (Important -> not only the new node but the whole cluster of nodes added till now)

```cpp
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> visited(V, 0);
        //wt, node
        pq.push({0,0});
        int sum = 0; 
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(visited[node] == 1)
                continue;
            else{
                visited[node] = 1;
                sum += wt;
                for(auto i : adj[node]){
                    int edw = i[1];
                    int adjNode = i[0];
                    pq.push({edw, adjNode});
                }
            }
        }
        
        return sum;
    }
```


### Kruskal's Algorithm
[[Kruskal's Algorithm]]
