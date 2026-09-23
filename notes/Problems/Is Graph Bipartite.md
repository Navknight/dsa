---
link: https://leetcode.com/problems/is-graph-bipartite/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "BFS 2-coloring from every uncolored node, same color on both ends of an edge = false"
time: "O(V + E)"
space: "O(V)"
date: 2023-08-17
---

# Problem
Can the nodes be split into two groups with every edge going across?

# Approach
## BFS 2-Coloring
Color each uncolored component's start 0, neighbours get the opposite color. A neighbour with the same color means not bipartite.

Bug in my code: inside the BFS it reads `graph[i]` and `colour[i]` instead of `graph[curr]` and `colour[curr]`, so only the start node's edges get checked.

### Code
```cpp
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> colour(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (colour[i] == -1)
        {
            queue<int> q;
            q.push(i);
            colour[i] = 0;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                int col = colour[i];

                for (int j = 0; j < graph[i].size(); j++)
                {
                    if (colour[graph[i][j]] == -1)
                    {
                        q.push(graph[i][j]);
                        colour[graph[i][j]] = !col;
                    }
                    else
                    {
                        if (colour[graph[i][j]] == col)
                            return false;
                    }
                }
            }
        }
        else
        {
            for (auto j : graph[i])
            {
                if (colour[j] == colour[i])
                    return false;
            }
        }
    }

    return true;
}
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V)$
