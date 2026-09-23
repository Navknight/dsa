---
link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
difficulty: Medium
topics:
  - "[[Graphs]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "Prim's: min pq of {wt, node}, skip visited, add wt when a node is first popped"
time: "O(E log E)"
space: "O(V + E)"
date: 
---

# Problem
Weight of the minimum spanning tree: connects all vertices, no cycles, min total weight.

# Approach
## Prim's
Start anywhere. Always add the smallest edge leaving the whole visited cluster. Min pq of `{wt, node}`, skip visited nodes.

### Code
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

### Complexity
- Time: $O(E \log E)$
- Space: $O(V + E)$

## Kruskal's
See [[Kruskal's Algorithm]].
