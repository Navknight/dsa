---
difficulty: Hard
topics: ["Dynamic Programming", "DFS"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/longest-increasing-path-in-a-matrix/"
date: 2026-09-04
---

[[Dynamic Programming]] [[DFS]]

# Problem
Given an `m x n` matrix, return the length of the longest strictly increasing path (4-directional moves, no diagonals), starting from any cell.

# Approach
## Naive DFS (no memo)
From every cell, DFS to neighbors, step only to a strictly greater neighbor. `solve(i,j)` returns the longest chain startable from `(i,j)`. Try every cell as start, take max. `solve(i,j)` recomputes every time it's reached, even within one DFS tree when two paths converge on the same cell.

### Code
```cpp
class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    int solve(vector<vector<int>>& matrix, int i, int j) {
        int ans = 0;
        for (int d = 0; d < 4; d++) {
            int ni = dx[d] + i, nj = dy[d] + j;

            if (ni >= 0 && nj >= 0 && ni < matrix.size() && nj < matrix[0].size() &&
                matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, solve(matrix, ni, nj) + 1);
            }
        }

        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, 1 + solve(matrix, i, j));
            }
        }

        return ans;
    }
};
```

### Complexity
- Time: $O(4^{rows \cdot cols})$
- Space: $O(rows \cdot cols)$ recursion stack

## DFS + Memoization
`dp[i][j]` = longest increasing chain startable from `(i,j)`, excluding itself. Depends only on grid values and position, not on how we got there. Cache it. `-1` marks uncomputed, real answers are always `>= 0` so no collision.

### Code
```cpp
class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for (int d = 0; d < 4; d++) {
            int ni = dx[d] + i, nj = dy[d] + j;

            if (ni >= 0 && nj >= 0 && ni < matrix.size() && nj < matrix[0].size() &&
                matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, solve(matrix, ni, nj) + 1);
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, 1 + solve(matrix, i, j));
            }
        }

        return ans;
    }
};
```

### Complexity
- Time: $O(rows \cdot cols)$
- Space: $O(rows \cdot cols)$
