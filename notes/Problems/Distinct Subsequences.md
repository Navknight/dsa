---
link: https://leetcode.com/problems/distinct-subsequences/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery: yellow
review: 2026-11-11
insight: "if chars match take or skip s[i], else skip. t exhausted = 1 way"
time: "O(m * n)"
space: "O(m * n)"
date: 2023-08-06
---

# Problem
Count distinct subsequences of `s` equal to `t`.

# Approach
## Recursion
Match: take (`i+1, j+1`) plus skip (`i+1, j`). No match: skip. `t` done = 1, `s` done = 0.

### Code
```cpp
int solve(string s, string t, int ind1, int ind2) {
    if (ind2 == t.size()) return 1;
    if (ind1 == s.size()) return 0;

    int ways = 0;
    if (s[ind1] == t[ind2]) ways = solve(s, t, ind1 + 1, ind2 + 1);
    return ways + solve(s, t, ind1 + 1, ind2);
}

int numDistinct(string s, string t) { return solve(s, t, 0, 0); }
```

### Complexity
- Time: $O(2^{m+n})$
- Space: $O(m+n)$

## Tabulation
Variant of [[Longest Common Subsequence]]. `dp[i][0] = 1`. Use `unsigned long long`, intermediates overflow.

### Code
```cpp
int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<unsigned long long int>> dp(m + 1, vector<unsigned long long int>(n + 1));
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 1;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // Adding where they match with the case where we dont take the character which matches from s.
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[m][n];
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$

## 1D Row
Row `i` only reads row `i + 1`. A mismatch changes nothing, so only matches update.

### Code
```cpp
int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<unsigned long long> dp(m + 1, 0);
    dp[m] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            if (s[i] == t[j]) dp[j] += dp[j + 1];
    return dp[0];
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(m)$

- 1D row: inner loop `j` must go ascending. `dp[j+1]` has to be the old row. `aaa` / `aa` is 3, descending gave 6
- Use `long long` or `unsigned long long`, cells that never feed the answer can overflow int
- Backtracking is the same recursion without the memo, exponential

### Mistakes
- Base cell is `dp[i][m] = 1` (t fully built), not column `m - 1`
- Match adds both branches, `dp[i+1][j+1] + dp[i+1][j]`. A `+ 1` only works on tiny cases
- Typo that cost a round: `for (j = 0; i < m; j++)`, the loop condition used `i`
