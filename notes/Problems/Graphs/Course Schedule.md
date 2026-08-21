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

[[Graphs]] [[Topological Sort]] [[DFS]] [[Cycle Detection]]

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
