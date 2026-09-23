---
link: https://leetcode.com/problems/longest-common-subsequence/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "match: 1 + dp[i-1][j-1], else max(dp[i-1][j], dp[i][j-1])"
time: "O(m * n)"
space: "O(m * n)"
date: 2026-08-23
---

# Problem
Length of the LCS of two strings.

# Approach
State `(i, j)`. Match: always take it. Else skip one char from either string, take the max.

## Memoization
Mistakes I made:
- Threaded a running length through the recursion, the cache stored path-dependent values.
- `unordered_map<pair<int,int>>` has no hash, used `map`.
- Sentinel 0 collides with real answers, use -1.

### Code
```cpp
class Solution {
public:
    map<pair<int, int>, int> mp;
    int solve(string& t1, string& t2, int start1, int start2) {
        if (start1 == t1.size() || start2 == t2.size()) return 0;
        if (mp.find({start1, start2}) != mp.end()) return mp[{start1, start2}];
        int take = 0, one = 0, second = 0;

        if (t1[start1] == t2[start2]) {
            take = 1 + solve(t1, t2, start1 + 1, start2 + 1);
        } else {
            one = solve(t1, t2, start1 + 1, start2);
            second = solve(t1, t2, start1, start2 + 1);
        }

        return mp[{start1, start2}] = max({one, second, take});
    }

    int longestCommonSubsequence(string text1, string text2) { return solve(text1, text2, 0, 0); }
};
```

### Complexity
- Time: $O(mn \log(mn))$ with `map`
- Space: $O(mn)$

## Tabulation
`dp[i][j]` = LCS of the first `i` and `j` chars. Compare `text1[i-1]`, `text2[j-1]`.

Mistake I made: compared `text1[i]`, reads `'\0'` at the end and fakes a match.

### Code
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};
```

### Complexity
- Time: $O(mn)$
- Space: $O(mn)$
