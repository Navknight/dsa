---
difficulty: Medium
topics: ["Graphs", "Matrix", "BFS"]
source: Standard
star: false
link: "https://leetcode.com/problems/rotting-oranges/"
---

[[Graphs]] [[Matrix]] [[BFS]]

# Problem
You are given an `m x n` `grid` where each cell can have one of three values:

- `0` representing an empty cell,
- `1` representing a fresh orange, or
- `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return _the minimum number of minutes that must elapse until no cell has a fresh orange_. If _this is impossible, return_ `-1`.

# Solution
Similar to [[Flood Fill]]
We will do a bfs as we need to keep time, which is analogous to levels in this question.
First we will push all the nodes which are initially 0 into the queue as they will be starting the rotting process and any nodes in contact to them will be turned to rotten at time=1

```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    vector<vector<bool>> visited(m, vector<bool> (n, 0));
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
                visited[i][j] = true;
                q.push({{i, j}, 0});
            }
            if(grid[i][j] == 1)
                count++;
        }
    }

    int time = 0;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();

        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(abs(i) == abs(j))
                    continue;
                else{
                    if((x+i) < 0 || (y+j) < 0 || (x+i) >= grid.size() || (y+j) >= grid[0].size())
                        continue;
                    if(!visited[x + i][y + j] && grid[x + i][y + j] == 1){
                        grid[x+i][y+j] = 2;
                        count--;
                        visited[x+i][y+j] =true;
                        q.push({{x+i, y+j}, t+1});
                    }
                }
            }
        }
        time = max(t, time);
    }

    return (count==0)?time:-1;
}
```