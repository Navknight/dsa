---
difficulty: Hard
topics: ["Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/distinct-subsequences/description/?envType=study-plan-v2&envId=dynamic-programming"
code: LeetCode/distinct_subsequences.cpp
---
[[LeetCode/distinct_subsequences.cpp]]
[[Dynamic Programming]]

# Problem

Given two strings `s` and `t`, return _the number of distinct_ **_subsequences**  _of_ `s` _which equals_ `t`.
The test cases are generated so that the answer fits on a 32-bit signed integer.

# Approach
## Brute Force Recursion
`solve(ind1, ind2)` = ways to match `t[ind2:]` using `s[ind1:]`. If `t` is exhausted, that's one valid way. If `s` is exhausted first, no way. Take `s[ind1]` if it matches `t[ind2]`, and always also skip `s[ind1]` (unconditional second call). No memo, overlapping states recompute.

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

## Bottom-Up DP Table
This problem is a variation of the [[Longest Common Subsequence]] question. Here since we have to match string `t` to a subsequence of `s`, we won't consider a case where we skip a letter of `t`. And to count the number of subsequences, we just add the cases where the characters match to the ones where we dont include that character.

unsigned long long int is used because the test cases get very large but the solution is under the int range so we have no issues returning int.

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