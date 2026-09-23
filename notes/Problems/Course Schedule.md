---
link: https://leetcode.com/problems/course-schedule/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Topological Sort]]"
  - "[[DFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "cycle in the prereq graph = can't finish. 3-color DFS or Kahn's count < n"
time: "O(V + E)"
space: "O(V + E)"
date: 2026-08-22
---

# Problem
Can all courses be finished given prerequisite pairs?

# Approach
## DFS, 3-Color
No cycle = finishable. See [[Cycle Detection]]. `0` unvisited, `1` on the current path, `2` done. Hitting a `1` is a back edge = cycle.

Mistakes I made:
- Ignored the recursive call's return value, so the cycle signal got lost.
- No early return on `color == 2`, TLE on shared prerequisites.

### Code
```cpp
class Solution {
public:
    bool dfs(vector<int>& color, int ind, vector<vector<int>>& graph) {
        if (color[ind] == 1)
            return true;
        if (color[ind] == 2)
            return false;

        color[ind] = 1;
        for (auto i : graph[ind]) {
            if (dfs(color, i, graph))
                return true;
            color[i] = 2;
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> color(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());

        for (auto v : prerequisites) {
            graph[v[0]].push_back(v[1]);
        }

        for (auto v : prerequisites) {
            if (color[v[0]] == 0) {
                if (dfs(color, v[0], graph)) {
                    return false;
                }
                color[v[0]] = 2;
            }
        }

        return true;
    }
};
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V + E)$

## Kahn's (BFS)
Push indegree 0 nodes, pop and decrement neighbours. Cycle nodes never reach 0, so `completed < n`. See [[Kahn's Algorithm]].

### Code
```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& v : prerequisites) {
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        int completed = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            completed++;

            for (int next : graph[node]) {
                if (--indegree[next] == 0)
                    q.push(next);
            }
        }

        return completed == numCourses;
    }
};
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V + E)$
