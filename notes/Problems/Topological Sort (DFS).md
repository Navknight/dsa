---
link: https://www.geeksforgeeks.org/problems/topological-sort/1
difficulty: Easy
topics:
  - "[[Graphs]]"
  - "[[DFS]]"
  - "[[Topological Sort]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "DFS, push a node on the stack after all its neighbours are done, pop for the order"
time: "O(V + E)"
space: "O(V)"
date: 
---

# Problem
Any topological order of a DAG.

# Approach
## DFS + Stack
Push a node after its DFS finishes, all its descendants are already on the stack. Pop everything. BFS version: [[Kahn's Algorithm]].

### Code
```cpp
void dfs(int node, vector<int> adj[],vector<bool> &visited, stack<int> &st){
    visited[node] = true;
    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }
    st.push(node);
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<bool> visited(V, 0);
    stack<int> st;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
    // code here
}
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V)$
