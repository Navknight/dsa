---
difficulty: Medium
topics: ["Graphs", "Floyd Warshall"]
source: Standard
star: false
---

[[Graphs]] [[Floyd Warshall]]

# Problem
##### Multi source shortest path algorithm
The problem is to find the shortest distances between every pair of vertices in a given **edge-weighted directed** graph. The graph is represented as an adjacency matrix of size **n\*n**. **Matrix\[i]\[j]** denotes the weight of the edge from **i to j.** If **Matrix\[i]\[j]=-1,** it means there is no edge from **i to j.**  
**Do it in-place.**

# Solution
Represented as an adjacency matrix, we can find the distance between two nodes as 'distance of x and y via z'. So, we calculate this distance between all the pairs of nodes via all the remaining nodes and the minimum is kept as the final distance between that pair of nodes.


```cpp
void shortest_distance(vector<vector<int>>&matrix){
	// Code here
	int n = matrix.size();
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == -1)
				matrix[i][j] = 1e9;
			
		if(i == j)
			matrix[i][j] = 0;
		}
	}
	
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == 1e9)
				matrix[i][j] = -1;
		}
	}
}
```

#### Negative cycles ->
If the graph contains a negative cycle, then in the final matrix there is going to be a pair `i, j` who have a distance < 0 between them

```cpp
for(int i = 0; i < n; i++){
	for (int j = 0; j < n; j++){
		if(matrix[i][j] < 0)
			return 1;
	}
}
```