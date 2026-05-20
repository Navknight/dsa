---
difficulty: Medium
topics: ["Graphs", "Topological Sort"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/topological-sort/"
---

[[Graphs]] [[Topological Sort]]

# Problem
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

# Solution
This algorithm is a way to find [[Topological Sort]] of a DAG. 


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