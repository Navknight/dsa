---
difficulty: Medium
topics: ["Graphs", "BFS", "Matrix"]
source: Standard
star: false
link: "https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1"
---

[[Graphs]] [[BFS]] [[Matrix]]

# Problem
Given a **n * m** matrix **grid** where each element can either be **0** or **1**. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return **-1**.

**Note :** You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing.

# Solution
Simple BFS from the source to the destination

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