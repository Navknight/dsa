---
link: https://leetcode.com/problems/find-eventual-safe-states/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[DFS]]"
  - "[[BFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "reverse the graph, Kahn's from terminal nodes. what gets popped is safe"
time: "O(V + E)"
space: "O(V + E)"
date: 
---

# Problem
Return nodes where every path ends at a terminal node, sorted.

# Approach
## DFS Cycle Detection
Nodes on a cycle or leading into one are unsafe. DFS with `pathVis`, mark `check[node] = true` only when the DFS finishes without a cycle.

### Code
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

### Complexity
- Time: $O(V + E)$
- Space: $O(V)$

## Reverse Graph + Kahn's
Reverse edges, terminal nodes now have indegree 0. [[Topological Sort]] from them, everything popped is safe. Sort the answer.

### Code
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

### Complexity
- Time: $O(V + E + V \log V)$
- Space: $O(V + E)$
