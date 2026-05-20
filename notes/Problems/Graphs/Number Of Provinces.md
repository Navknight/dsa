---
difficulty: Medium
topics: ["Graphs", "DFS", "Disjoint Set Union"]
source: Standard
star: false
link: "https://leetcode.com/problems/number-of-provinces/"
---

[[Graphs]] [[DFS]] [[Disjoint Set Union]]

# Problem
There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return _the total number of **provinces**_.

# Solution
Related to the [[Number Of Islands]] Problem, very similar solution but it is an undirected graph here so easier


## DFS
```cpp
void dfs(vector<vector<int>> &isConnected, int node, vector<bool> &visited){
    visited[node] = true;
    for(int i = 0; i < isConnected.size(); i++){
        if(isConnected[node][i] && !visited[i]){
                dfs(isConnected, i, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, 0);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            count++;
            dfs(isConnected, i, visited);
        }
    }

    return count;
}
```


## DSU
This solution uses the [[Disjoint Set Union]]
```cpp
int findCircleNum(vector<vector<int>>& isConnected) {
	int n = isConnected.size();
	DSU dsu(n);
	int count = n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(isConnected[i][j] == 1){
				if(dsu.findUPar(i) != dsu.findUPar(j)){
					count--;
					dsu.join(i, j);
				}
			} 
		}
	}

	return count;
}
```