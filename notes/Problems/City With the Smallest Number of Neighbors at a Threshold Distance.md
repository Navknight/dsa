---
link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
difficulty: Easy
topics:
  - "[[Graphs]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "Floyd Warshall for all pairs, count reachable per city, ties go to the larger index (<=)"
time: "O(n³)"
space: "O(n²)"
date: 
---

# Problem
Find the city with the fewest cities within `threshold` distance. Ties go to the larger city number.

# Approach
## Floyd Warshall
[[Floyd Warshall Algorithm]] for all-pairs distances, then count per city. Use `<=` when comparing counts so later cities win ties.

### Code
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

### Complexity
- Time: $O(n^3)$
- Space: $O(n^2)$
