---
link: https://leetcode.com/problems/01-matrix/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "multi-source BFS from every 0, relax dist when it improves"
time: "O(m * n)"
space: "O(m * n)"
date: 2023-02-15
---

# Problem
Distance from each cell to the nearest 0.

# Approach
## Multi-Source BFS
Push every 0 at distance 0. Relax neighbours when `dist + 1` is smaller. Same as [[Distance of nearest cell having 1]].

### Code
```cpp
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
                q.push({ i, j }); //Put all 0s in the queue.
            }
        }
    }

    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
            if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                    q.push({ new_r, new_c });
                }
            }
        }
    }
    return dist;
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
