---
link: https://www.geeksforgeeks.org/problems/topological-sort/1
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Topological Sort]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "push indegree 0 nodes, pop and decrement neighbours, the pop order is the topo sort"
time: "O(V + E)"
space: "O(V)"
date: 
---

# Problem
Any topological order of a DAG.

# Approach
## BFS on Indegree
[[Topological Sort]] with a queue. Push indegree 0, pop, decrement neighbours, push the ones that hit 0.

### Code
```cpp
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int> indegree (V, 0);
    for(int i = 0; i < V; i++){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; i++)
        if(indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }

    return topo;
}
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V)$
