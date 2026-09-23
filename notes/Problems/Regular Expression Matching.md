---
link: https://leetcode.com/problems/regular-expression-matching/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
  - "[[Strings]]"
  - "[[Recursion]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "if p[j+1] == '*': skip the pair (j+2) or eat one char if it matches (i+1). memo on (i, j)"
time: "O(mn)"
space: "O(mn)"
date: 2026-09-14
---

# Problem
Regex match with `.` and `*`, full string.

# Approach
## Recursion
Look ahead for `*`. Match: eat one and stay (`i+1, j`) or skip the pair (`i, j+2`). Mismatch: skip the pair only.

Trap: skipping keeps `i` fixed even on a match, the char may belong to what follows.

Branch order changes TLE without memo, that's luck, memoize.

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
- Time: $O(2^{m+n})$
- Space: $O(m+n)$

## Memoization

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
- Space: $O(mn)$

## Tabulation
`dp[i][j]` = `s[i:]` matches `p[j:]`. Base row `dp[m][j]` is true only if `p[j:]` is all `x*` pairs.

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
