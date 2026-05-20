---
type: reference
topic: Prefix Sum
---

# Prefix Sum

Precompute cumulative sums for O(1) range sum queries. Extend to 2D for matrix range sums.

## When to Use

- Range sum queries
- Subarray sum == k
- Count subarrays with property
- 2D range queries

## Template

```cpp
// 1D prefix sum
vector<int> buildPrefix(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
    return prefix;
}
// Query sum [l, r] (0-indexed)
int rangeSum(vector<int>& prefix, int l, int r) {
    return prefix[r+1] - prefix[l];
}

// 2D prefix sum
vector<vector<int>> build2D(vector<vector<int>>& mat) {
    int r = mat.size(), c = mat[0].size();
    vector<vector<int>> p(r+1, vector<int>(c+1, 0));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            p[i][j] = mat[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    return p;
}
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "Prefix Sum")
sort difficulty asc, file.name asc
```
