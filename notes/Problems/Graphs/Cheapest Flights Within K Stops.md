---
difficulty: Medium
topics: ["Graphs", "Dijkstra"]
source: Standard
star: false
link: "https://leetcode.com/problems/cheapest-flights-within-k-stops/description/"
---

[[Graphs]] [[Dijkstra]]

# Problem
There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return _**the cheapest price** from_ `src` _to_ `dst` _with at most_ `k` _stops._ If there is no such route, return `-1`.

# Solution
Same as [[Dijkstra's Algorithm]] but here we don't need a priority queue and a normal queue is enough as our primary goal is to have at max K stops, so we want the queue to be ordered according to the number of stops. That will automatically happen as the number of stops increases by one after every node.
The time complexity of this question is `E` as there is no priority queue to take up an extra `log(V)` time.

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