---
link: https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "plain BFS on 1-cells, first time you reach the destination is the answer"
time: "O(n * m)"
space: "O(n * m)"
date: 
---

# Problem
Shortest path from source to destination moving through 1s, 4 directions.

# Approach
## BFS
Unit weights, so BFS gives the shortest distance.

### Code
```cpp
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination) {
    // code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n, vector<int> (m, 1e9));
    queue<pair<int, pair<int, int>>> q;
    distance[source.first][source.second] = 0;
    if(source == destination)
        return 0;
    q.push({0, source});
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    while(!q.empty()){
        int dis = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int newr = r + dx[i];
            int newc = c + dy[i];

            if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && distance[newr][newc] > dis + 1){
                distance[newr][newc] = dis + 1;
                q.push({distance[newr][newc], {newr, newc}});

                if(newr == destination.first && newc == destination.second)
                    return distance[newr][newc];
            }
        }
    }

    return -1;
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n \cdot m)$
