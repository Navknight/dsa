---
difficulty: Easy
topics: ["Graphs", "Floyd Warshall"]
source: Standard
star: false
link: "https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance"
---

[[Graphs]] [[Floyd Warshall]]

# Problem
There are n cities numbered from 0 to n-1. Given the array edges where **edges\[i] = \[fromi , toi ,weighti]**  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is **at most** Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.

# Solution
### Floyd Warshall
We first use [[Floyd Warshall Algorithm]] to find the distance between all the cities and then use a simple frequency count to find the desired city

```cpp
int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
                     vector<vector<int>> grid(n, vector<int> (n, 1e9));
                     for(int i = 0; i < m; i++){
                         grid[edges[i][0]][edges[i][1]] = edges[i][2];
                         grid[edges[i][1]][edges[i][0]] = edges[i][2];
                     }
                     
                     for(int i = 0; i < n; i++) grid[i][i] = 0;
                     for(int k = 0; k < n; k++){
                         for(int i = 0; i < n; i++){
                             for(int j = 0; j < n; j++){
                                 grid[i][j] = min(grid[i][k] + grid[k][j], grid[i][j]);
                             }
                         }
                     }
                     
                     int count = n+1;
                     int city = -1;
                     
                     for(int i = 0; i < n; i++){
                         int c = 0;
                         for(int j = 0; j < n; j++){
                             if(grid[i][j] <= distanceThreshold)
                                c++;
                         }
                         if(c <= count){
                            count = c;
                            city = i;
                         }
                     }
                     
                     return city;
                 }
```