---
link: https://leetcode.com/problems/path-with-minimum-effort/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Dijkstra]]"
  - "[[Binary Search]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "Dijkstra where path cost = max edge diff so far"
time: "O(mn log(mn))"
space: "O(mn)"
date: 
---

# Problem
Min over paths of the max height difference between consecutive cells.

# Approach
## Dijkstra
[[Dijkstra's Algorithm]] with distance = `max(dist to parent, |height diff|)`.

### Code
```cpp
int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    distance[0][0] = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if (r == n - 1 && c == m - 1)
            return dis;

        for (int i = 0; i < 4; i++)
        {
            int newr = r + dx[i];
            int newc = c + dy[i];

            if (newr >= 0 && newr < n && newc >= 0 && newc < m && max(dis, abs(heights[newr][newc] - heights[r][c])) < distance[newr][newc])
            {
                distance[newr][newc] = max(dis, abs(heights[newr][newc] - heights[r][c]));
                pq.push({distance[newr][newc], {newr, newc}});
            }
        }
    }
    return distance[n - 1][m - 1];
}
```

### Complexity
- Time: $O(mn \log(mn))$
- Space: $O(mn)$
