---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/interleaving-string/"
date: 2026-09-04
---

[[Dynamic Programming]]

# Problem
Given `s1`, `s2`, `s3`, check if `s3` is formed by interleaving `s1` and `s2` (relative order of each string's chars is preserved).

# Approach
## Brute Force Recursion
State `(ind1, ind2)` = chars placed from `s1`, `s2` so far. Next char to match in `s3` is at `ind1+ind2`. Take from `s1` if it matches, or from `s2` if it matches, recurse. No memo, overlapping states recompute.

### Code
```cpp
class Solution {
public:
    bool solve(string s1, string s2, string s3, int ind1, int ind2) {
        if (ind1 == s1.size() && ind2 == s2.size()) {
            if (ind1 + ind2 == s3.size()) return true;
        }

        if (ind1 < s1.size() && s1[ind1] == s3[ind1 + ind2] && solve(s1, s2, s3, ind1 + 1, ind2))
            return true;

        if (ind2 < s2.size() && s2[ind2] == s3[ind1 + ind2] && solve(s1, s2, s3, ind1, ind2 + 1))
            return true;

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) { return solve(s1, s2, s3, 0, 0); }
};
```

### Complexity
- Time: $O(2^{m+n})$
- Space: $O(m+n)$

## Bottom-Up DP Table
`dp[i][j]` = can `s1[i:]` and `s2[j:]` interleave into `s3[i+j:]`. Base case `dp[m][n] = true`. Fill `i` and `j` from high to low so `dp[i+1][j]` and `dp[i][j+1]` are ready first. Pull a char from `s1` or `s2` if it matches the next `s3` char.

### Code
```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[m][n] = 1;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i + 1 <= m && s1[i] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i + 1][j];
                if (j + 1 <= n && s2[j] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
