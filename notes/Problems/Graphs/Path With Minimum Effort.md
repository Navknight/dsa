---
difficulty: Medium
topics: ["Graphs", "Dijkstra"]
source: Standard
star: false
link: "https://leetcode.com/problems/path-with-minimum-effort/"
---

[[Graphs]] [[Dijkstra]]

# Problem
You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., **0-indexed**). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference** in heights between two consecutive cells of the route.

Return _the minimum **effort** required to travel from the top-left cell to the bottom-right cell._

# Solution
Using the [[Dijkstra's Algorithm]] we can find the path with minimum effort, the only thing different is how we calculate the distance -> which will be the max(dis to parent, difference between height)

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