---
difficulty: Medium
topics:
  - Dynamic Programming
  - Recursion
  - Math
source: Leetcode
star: false
link: https://leetcode.com/problems/unique-paths/
code: LeetCode/unique_paths.cpp
date: 2026-08-22
---

[[LeetCode/unique_paths.cpp]]
[[Dynamic Programming]] [[Recursion]] [[Math]]

# Problem
A robot starts at the top-left corner of an `m x n` grid and can only move right or down. Return the number of distinct paths to reach the bottom-right corner.

# Approach
2D DP: state is the pair `(i,j)` since position in a grid needs both coordinates, not a single index. `dp[i][j] = dp[i-1][j] + dp[i][j-1]` — the last move to reach `(i,j)` was either a down-move from `(i-1,j)` or a right-move from `(i,j-1)`. Base case: every cell in the top row or left column is `1`, not because of the grid's shape, but because the only-right-or-down movement restriction leaves exactly one possible sequence of moves to reach any edge cell (all rights, or all downs).

## Backtracking
Represent each path as a string of moves (`1` = right, `0` = down), recursing on the remaining `m`/`n`. Recalculates the same subproblems repeatedly, and pays extra overhead storing paths in a `set`.

```cpp
void backtrack(int m, int n, string &path, set<string> &paths, int size)
{
    if (path.size() == size)
    {
        paths.insert(path);
    }
    else
    {
        if (m > 1)
        {
            path.push_back(1);
            backtrack(m - 1, n, path, paths, size);
            path.pop_back();
        }
        if (n > 1)
        {
            path.push_back(0);
            backtrack(m, n - 1, path, paths, size);
            path.pop_back();
        }
    }
}
```
`size = m + n - 2`, the total number of moves needed.

### Complexity
- Time: exponential (recomputes overlapping subproblems, plus `set` overhead)
- Space: exponential

## Bottom-Up DP (2D Table)
Standard fill, forward from `(0,0)`.

### Code
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int i = 0; i < m; i++) dp[i][0] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
```

### Complexity
- Time: $O(mn)$
- Space: $O(mn)$

## Bottom-Up DP (Rolling 1D Array)
`dp[i][j]` only ever needs `dp[i-1][j]` (row above, same column) and `dp[i][j-1]` (current row, one column back) — never the whole table. Collapse to a single rolling array updated in place: `dp[j] = dp[j] + dp[j-1]`, where the right-hand `dp[j]` is still last row's value (not yet overwritten this pass) and `dp[j-1]` was already updated earlier in the current row.

Unlike the closed-form combinatorial solution below, this still generalizes to Unique Paths II (obstacles), where the binomial trick doesn't apply.

### Code
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
```

### Complexity
- Time: $O(mn)$
- Space: $O(n)$

## Combinatorial (Optimal, Not DP)
Every path takes exactly `m-1` down-moves and `n-1` right-moves in some order — a path is just an arrangement of `(m-1)` D's and `(n-1)` R's among `m+n-2` total moves. Count of distinct arrangements is $\binom{m+n-2}{m-1}$. Only works because there are no obstacles to route around; Unique Paths II needs actual DP.

Multiply-then-divide-by-`i` (rather than a full factorial then one division) keeps every intermediate result an exact integer, avoiding overflow.

### Code
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        int total = m + n - 2;
        int k = min(m, n) - 1;
        for (int i = 1; i <= k; i++) {
            result = result * (total - k + i) / i;
        }
        return (int)result;
    }
};
```

### Complexity
- Time: $O(\min(m,n))$
- Space: $O(1)$
