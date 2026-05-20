---
difficulty: Medium
topics: ["Graphs", "Disjoint Set Union"]
source: Standard
star: true
---

[[Graphs]] [[Disjoint Set Union]]

# Problem
Given a series of instructions asking to join two vertices, we join them and also serve answers to questions like if two nodes are already in the same component or not.

## DSU By Rank

The rank is not the same as height, every time a new node is attached to a component, the rank of the ultimate parent of that component goes up by one.

## DSU By Size
The size is similar to height but instead counts all the nodes in the current component for that particular parent, but doesn't go down when the component is attached to another node.

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
        if (rank[ulp_u] < rank[ulp_v])
		    parent[ulp_u] = ulp_v;
		else if (rank[ulp_u] > rank[ulp_v])
		    parent[ulp_v] = ulp_u;
		else {
		    parent[ulp_v] = ulp_u;
		    rank[ulp_u]++;
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
```