---
difficulty: Hard
topics:
  - Dynamic Programming
  - Strings
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/regular-expression-matching/
date: 2026-09-14
---

[[Dynamic Programming]] [[Strings]] [[Recursion]]

# Problem
Implement regex matching for `.` (any single char) and `*` (zero or more of the preceding element). Match must cover the entire input string.

# Approach
## Recursion
Look ahead at `p[ind2+1]` to detect a `*`. On a char match, branch: consume one and keep repeating (`ind1+1, ind2`), or take zero occurrences (`ind1, ind2+2`). On a mismatch, zero occurrences is the only option. Otherwise it's a plain one-char match.

Key trap: zero-occurrence must keep `ind1` fixed even when the current char matches — the char isn't obligated to be eaten by the star, it may belong to whatever follows the pair. Exponential without memoization (overlapping `(ind1, ind2)` subproblems).

### Code
```cpp
bool solve(string s, string p, int ind1, int ind2) {
    if (ind1 == s.size() && ind2 == p.size())
        return true;
    if (ind2 == p.size())
        return false;

    if (ind2 + 1 < p.size() && p[ind2 + 1] == '*') {
        if (ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.'))
            return solve(s, p, ind1 + 1, ind2) ||
                   solve(s, p, ind1, ind2 + 2);
        else
            return solve(s, p, ind1, ind2 + 2);
    } else if (ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.'))
        return solve(s, p, ind1 + 1, ind2 + 1);
    else
        return false;
}
```

### Complexity
- Time: $O(2^{m+n})$ worst case
- Space: $O(m+n)$ recursion stack

Note: branch order matters without memoization. Trying "consume one" before "skip the star pair" (as above) TLEs on LeetCode's catastrophic-backtracking test case (long run of one char vs a pattern like `a*a*a*...c` that never matches). Trying skip-first happens to prune that case fast and passes, but it's judge-specific luck, not a real complexity improvement. Memoize instead of relying on branch order.

## Memoized Recursion
Same recursion, cache on `(ind1, ind2)` to kill the branch-order dependence and guarantee $O(mn)$.

### Code
```cpp
bool solve(string &s, string &p, int ind1, int ind2, vector<vector<int>> &memo) {
    if (ind1 == s.size() && ind2 == p.size())
        return true;
    if (ind2 == p.size())
        return false;
    if (memo[ind1][ind2] != -1)
        return memo[ind1][ind2];

    bool res;
    if (ind2 + 1 < p.size() && p[ind2 + 1] == '*') {
        if (ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.'))
            res = solve(s, p, ind1 + 1, ind2, memo) ||
                  solve(s, p, ind1, ind2 + 2, memo);
        else
            res = solve(s, p, ind1, ind2 + 2, memo);
    } else if (ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.'))
        res = solve(s, p, ind1 + 1, ind2 + 1, memo);
    else
        res = false;

    return memo[ind1][ind2] = res;
}
```

### Complexity
- Time: $O(mn)$
- Space: $O(mn)$ memo + $O(m+n)$ recursion stack

## Bottom-Up DP
`dp[i][j]` = does `s[i:]` match `p[j:]`.

Base row `dp[m][j]`: empty string only matches `p[j:]` if it's all `char*` pairs from there on, computed right to left, not a blanket `true`.

### Code
```cpp
bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[m][n] = true;
    for (int j = n - 1; j >= 0; j--)
        dp[m][j] = (j + 1 < n && p[j + 1] == '*') ? dp[m][j + 2] : false;

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (j + 1 < n && p[j + 1] == '*') {
                if (s[i] == p[j] || p[j] == '.')
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 2];
                else
                    dp[i][j] = dp[i][j + 2];
            } else if (s[i] == p[j] || p[j] == '.')
                dp[i][j] = dp[i + 1][j + 1];
            else
                dp[i][j] = false;
        }
    }

    return dp[0][0];
}
```

### Complexity
- Time: $O(mn)$
- Space: $O(mn)$
