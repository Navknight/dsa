---
link: https://leetcode.com/problems/unique-paths/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
  - "[[Math]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "dp[j] += dp[j-1] row by row, or C(m+n-2, m-1)"
time: "O(min(m,n))"
space: "O(1)"
date: 2026-08-22
---

# Problem
Count right/down paths from top-left to bottom-right.

# Approach
`dp[i][j] = dp[i-1][j] + dp[i][j-1]`, top row and left column are 1.

## Backtracking
Build every path as a string in a set. Exponential.

### Code
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

## 2D Table

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

## 1D Rolling
`dp[j] += dp[j-1]`. Still works with obstacles, unlike the formula.

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

## Combinatorics
`C(m+n-2, m-1)`. Multiply then divide by `i` each step to stay exact.

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
- Time: $O(\min(m, n))$
- Space: $O(1)$
