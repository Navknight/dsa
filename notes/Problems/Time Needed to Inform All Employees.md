---
link: https://leetcode.com/problems/time-needed-to-inform-all-employees/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "build manager -> reports tree, DFS from head, time = informTime + max over children"
time: "O(n)"
space: "O(n)"
date: 2023-04-07
---

# Problem
Time for news from the head to reach every employee.

# Approach
## DFS on the Tree
Map each manager to their reports. DFS from `headID`: time = `informTime[u] + max(child times)`.

### Code
```cpp
int dfs(int headID, vector<int> &informTime, unordered_map<int, vector<int>> &m)
{
    int max_time = 0;
    for (int child : m[headID])
    {
        max_time = max(max_time, dfs(child, informTime, m));
    }
    return informTime[headID] + max_time;
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        if (i == headID)
        {
            continue;
        }
        m[manager[i]].push_back(i);
    }
    return dfs(headID, informTime, m);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
