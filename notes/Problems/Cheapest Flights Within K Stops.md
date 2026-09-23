---
link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[Dijkstra]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "BFS ordered by stops, not a pq by cost. stop expanding once stops > k"
time: "O(E * k)"
space: "O(V + E)"
date: 
---

# Problem
Cheapest price from `src` to `dst` with at most `k` stops, else -1.

# Approach
## BFS by Stops
Like [[Dijkstra's Algorithm]] but the constraint is stops, so a plain queue works. Stops go up by one each level, so the queue stays ordered by stops. Relax only while `stops <= k`.

### Code
```cpp
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for(auto i : flights){
        adj[i[0]].push_back({i[1], i[2]});
    }    
    queue<pair<int, pair<int, int>>> q;
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    q.push({0, {src, 0}});

    while(!q.empty()){
        int stops = q.front().first;
        int city = q.front().second.first;
        int dis = q.front().second.second;
        q.pop();

        for(auto i:adj[city]){
            if(stops <= k){
                if(distance[i.first] > dis + i.second){
                    distance[i.first] = dis + i.second;
                    q.push({stops+1, {i.first, distance[i.first]}});
                }
            }
        }
    }

    return (distance[dst] == 1e9)?-1:distance[dst];
}
```

### Complexity
- Time: $O(E \cdot k)$
- Space: $O(V + E)$
