---
type: reference
topic: Floyd Warshall
---

# Floyd Warshall

All-pairs shortest path. O(V³). Handles negative edges (not negative cycles).

## When to Use

- All-pairs shortest path
- Small graphs (V ≤ 500)
- Detect negative cycles

## Template

```cpp
// Floyd-Warshall
void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
```

## Problems

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "Floyd Warshall")
sort difficulty asc, file.name asc
```
