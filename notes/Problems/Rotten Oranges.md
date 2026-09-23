---
link: https://leetcode.com/problems/rotting-oranges/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Arrays]]"
  - "[[BFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "multi-source BFS from all rotten oranges, levels are minutes, -1 if any fresh is left"
time: "O(m * n)"
space: "O(m * n)"
date: 
---

# Problem
Minutes until every orange is rotten, or -1.

# Approach
## Multi-Source BFS
Push every rotten orange at time 0. Each BFS level is one minute. Any fresh orange left means -1.

### Code
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

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
