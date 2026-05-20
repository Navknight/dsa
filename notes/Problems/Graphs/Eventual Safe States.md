---
difficulty: Medium
topics: ["Graphs", "Cycle Detection", "BFS"]
source: Standard
star: false
link: "https://leetcode.com/problems/find-eventual-safe-states/"
---

[[Graphs]] [[Cycle Detection]] [[BFS]]

# Problem
There is a directed graph of `n` nodes with each node labeled from `0` to `n - 1`. The graph is represented by a **0-indexed** 2D integer array `graph` where `graph[i]` is an integer array of nodes adjacent to node `i`, meaning there is an edge from node `i` to each node in `graph[i]`.

A node is a **terminal node** if there are no outgoing edges. A node is a **safe node** if every possible path starting from that node leads to a **terminal node** (or another safe node).

Return _an array containing all the **safe nodes** of the graph_. The answer should be sorted in **ascending** order.

# Solution
We can make two observations -
1. If a node is part of a cycle, they can never be safe
2. if a node leads to a cycle they can never be safe

so we use the [[Detect cycle in Undirected graph]] algorithm using DFS to find cycles and modify the safe nodes array

```cpp
bool dfs(int node, vector<vector<int>>& graph, vector<bool> &visited, vector<bool> &pathVis, vector<bool> &check){
    visited[node] = true;
    pathVis[node] = true;
    check[node] = false;

    for(auto i : graph[node]){
        if(!visited[i]){
            if(dfs(i, graph, visited, pathVis, check)){
                check[node] = 0;
                return true;
            }
        }
        else if(pathVis[i]){
            check[node] = false;
            return true;
        }
    }

    check[node] = true;
    pathVis[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, 0);
    vector<bool> pathVis(n, 0);
    vector<bool> check(n, 0);
    vector<int> safe;

    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i, graph, visited, pathVis, check);
    

    for(int i = 0; i < n; i++)
        if(check[i])
            safe.push_back(i);
    
    return safe;
}
```


## Using BFS
Reverse the graph, now the nodes with indegree 0 are safe states so any node connected to them will have eventual safe state if we find them in [[Topological Sort]], i.e. if their parent is removed they should have indegree 0 as well

```cpp
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> rev(n);
    vector<int> indegree(n);

    for(int i = 0; i < n; i++){
        for(auto j : graph[i]){
            rev[j].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            q.push(i);

    
    vector<int> ans;

    while(!q.empty()){
        int curr = q.front(); q.pop();
        ans.push_back(curr);
        for(auto i : rev[curr]){
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}
```