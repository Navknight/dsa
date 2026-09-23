---
link: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Disjoint Set Union]]"
source: Standard
star: true
blind75: false
mastery:
review:
insight: "path compression + union by size/rank, near O(1) per op"
time: "O(α(n)) per op"
space: "O(n)"
date: 
---

# Problem
Union two nodes and check if two nodes are in the same component.

# Approach
## Path Compression + Union by Rank/Size
`findUPar` points every node straight at the root. Union attaches the smaller tree under the bigger one.

By rank: rank only goes up when two equal ranks join. By size: count of nodes in the component.

### Code
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

### Complexity
- Time: $O(\alpha(n))$ per op
- Space: $O(n)$
