---
difficulty: Hard
topics: ["Graphs", "MST", "Disjoint Set Union"]
source: Standard
star: false
---

[[Graphs]] [[MST]] [[MST]] [[Disjoint Set Union]]

# Problem
This is an algorithm to find the [[Minimum Spanning Tree]] of a graph.

# Solution
Sort all the edges by their weight, now at each iteration choose the smallest edge and add it to the MST.
This algo uses [[Disjoint Set Union]] to find if the edge that is being chosen connects vertices which already are connected by any path in the MST or not

```cpp
class DSU
{
    vector<int> parent, rank, size;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        else if (ulp_u > ulp_v)
            parent[v] = u;
        else if (ulp_u < ulp_v)
            parent[u] = v;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v == ulp_u)
            return;
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        DSU ds(V);
        sort(edges.begin(), edges.end());
        
        int mstWt = 0;
        for(auto it : edges){
            int wt = it.first;
            int node = it.second.first;
            int adjNode = it.second.second;
            
            if(ds.findUPar(node) != ds.findUPar(adjNode)) {
                mstWt += wt;
                ds.unionBySize(node, adjNode);
            }
        }
        
        return mstWt;
    }
};
```