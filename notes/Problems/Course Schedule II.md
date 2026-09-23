---
link: https://leetcode.com/problems/course-schedule-ii/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Topological Sort]]"
  - "[[BFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "Kahn's, the pop order is the answer. order.size() < n = cycle"
time: "O(V + E)"
space: "O(V + E)"
date: 2026-08-29
---

# Problem
Return any valid course order, or `[]` if impossible.

# Approach
Same as [[Course Schedule]], Kahn's pop order is the answer.

## Adjacency Matrix
Works but wasteful for a sparse graph.

### Code
```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));

        for (auto course : prerequisites) {
            graph[course[0]][course[1]] = 1;
        }

        queue<int> q;
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < numCourses; j++)
                indegree[i] += graph[i][j];

            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (int i = 0; i < numCourses; i++) {
                if (graph[i][curr] == 1) {
                    indegree[i]--;
                    if (indegree[i] == 0)
                        q.push(i);
                    graph[i][curr] = 0;
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};
```

### Complexity
- Time: $O(V^2)$
- Space: $O(V^2)$

## Adjacency List

### Code
```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);

        vector<int> order;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            for (auto i : graph[curr])
                if (--indegree[i] == 0) q.push(i);
        }

        return order.size() == numCourses ? order : vector<int>();
    }
};
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V + E)$
