---
difficulty: Medium
topics: ["Graphs", "BFS"]
source: Standard
star: false
link: "https://leetcode.com/problems/shortest-path-in-binary-matrix/description/"
---

[[Graphs]] [[BFS]]

# Problem
Given an `n x n` binary matrix `grid`, return _the length of the shortest **clear path** in the matrix_. If there is no clear path, return `-1`.

A **clear path** in a binary matrix is a path from the **top-left** cell (i.e., `(0, 0)`) to the **bottom-right** cell (i.e., `(n - 1, n - 1)`) such that:

- All the visited cells of the path are `0`.
- All the adjacent cells of the path are **8-directional** connected (i.e., they are different and they share an edge or a corner).

The **length of a clear path** is the number of visited cells of this path.

# Solution
[[Shortest Distance in a Binary Maze]] exactly the same with a minor tweak.

```cpp
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0] == 1)
        return -1;
    
    int s = grid.size();
    if(grid[s-1][s-1] != 0)
        return -1;

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    grid[0][0] = -1;

    int drow[] = {-1, 0, +1, 0, 1, -1, -1, 1};
    int dcol[] = {0, 1, 0, -1, 1, 1, -1, -1}; 

    while(!q.empty()){
        auto val = q.front();
        int i = val.first.first;
        int j = val.first.second;
        int path = val.second;
        q.pop();

        if(i == s-1 && j == s-1)
            return path;

        for(int idx=0;idx<8;idx++){
            int row = i + drow[idx];
            int col = j + dcol[idx];

            if(row >= 0 && row < s && col >= 0 && col < s && grid[row][col] == 0){
                grid[row][col] = -1;
                q.push({{row, col}, path+1});
            }
        }
    }

    return -1;
}
```