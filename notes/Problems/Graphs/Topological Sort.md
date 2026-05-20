---
difficulty: Easy
topics: ["Graphs", "DFS", "Topological Sort"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/topological-sort/"
---

[[Graphs]] [[DFS]] [[Topological Sort]]

# Problem
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
# Solution
To find a topological sort, we maintain a stack. whenever we visit a new node, after performing DFS we push the node onto the stack as all the neighbors of that node will already be on the stack due to the recursive nature of the DFS function
Then we pop the elements and store them in an array

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
