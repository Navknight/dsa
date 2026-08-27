---
difficulty: Medium
topics:
  - Graphs
  - Topological Sort
  - DFS
source: Leetcode
star: false
link: https://leetcode.com/problems/course-schedule/
date: 2026-08-22
---

[[Graphs]] [[Topological Sort]] [[DFS]] [[Cycle Detection]] [[Kahn's Algorithm]]

# Problem
Given `numCourses` and a list of prerequisite pairs `[a, b]` meaning course `a` requires course `b` first, determine whether all courses can be finished.

# Approach
## Directed Cycle Detection (DFS, 3-color)
All courses can be finished iff the prerequisite graph has no cycle — a cycle means a set of courses that all transitively require each other, so none of them can ever be taken first. See [[Cycle Detection]].

Build an adjacency list from `a -> b` for each prerequisite pair, then DFS with 3 states per node:
- `0` = unvisited
- `1` = in-stack (currently on the active recursion path)
- `2` = done (fully explored, proven cycle-free)

Hitting a neighbor colored `1` is a back edge to a node still on the current path — that's the cycle. Hitting a neighbor colored `2` means that subtree was already proven safe, so skip it entirely rather than re-exploring.

Bugs hit along the way, worth remembering:
- First attempt called `dfs(color, i, graph)` on each neighbor but never checked the return value — the recursive call correctly computed `true` on a back edge, but that signal was silently discarded one stack frame at a time, so `canFinish` never saw a cycle. Traced on `prerequisites = [[0,1],[1,0]]`: the innermost call does detect the back edge and return `true`, but the loop that called it (`for (auto i : graph[ind]) dfs(color, i, graph);`) ignores the result, and the whole thing incorrectly returns `true` (can finish) for a 2-node cycle.
- After fixing that, TLE: no check for `color[ind] == 2` at entry meant already-fully-verified subtrees got re-explored every time a different path converged on them (diamond dependency shape: two courses sharing a common prerequisite). Without short-circuiting on `2`, this blows up on graphs where many nodes converge on shared ancestors — the whole point of the `2` state is memoization, and without checking it, that memoization never kicks in.

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
- Time: $O(V + E)$ — each node's DFS body runs once thanks to the `color == 2` short-circuit
- Space: $O(V + E)$ for the adjacency list, plus $O(V)$ recursion stack

## Kahn's Algorithm (BFS, In-Degree)
Same $O(V+E)$ complexity as the DFS version, but iterative — no recursion stack, so no depth-limit risk on large `numCourses`. Also the more natural base if the problem ever asks for the actual order (Course Schedule II), since Kahn's produces that order as a byproduct; the DFS version would need a separate reverse-postorder step bolted on. See [[Kahn's Algorithm]].

Build the graph in the same prerequisite direction (`b -> a` for `a` requires `b`) and track in-degree per node. Seed a queue with every node that has in-degree `0` (no prerequisites — can be taken immediately). Repeatedly pop a node, count it as completed, and decrement the in-degree of everything it points to, pushing any that drop to `0`. If a cycle exists, every course in it is permanently waiting on another course in the same cycle, so its in-degree never reaches `0` and it's never pushed — the final completed count comes up short of `numCourses`.

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
- Space: $O(V + E)$ for the adjacency list and in-degree array, plus $O(V)$ for the queue
