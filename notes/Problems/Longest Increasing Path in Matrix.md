---
link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "DFS + memo, dp[i][j] = longest path starting here. strictly increasing means no cycles"
time: "O(rows * cols)"
space: "O(rows * cols)"
date: 2026-09-04
---

# Problem
Longest strictly increasing path in a grid, 4 directions.

# Approach
## DFS
From every cell, step only to a greater neighbour.

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
- Time: exponential
- Space: $O(rows \cdot cols)$

## DFS + Memo
`dp[i][j]` only depends on the cell, not the path, so cache it. Strictly increasing means no cycles, no visited array needed.

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
