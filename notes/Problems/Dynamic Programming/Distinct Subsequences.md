---
difficulty: Hard
topics: ["Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/distinct-subsequences/description/?envType=study-plan-v2&envId=dynamic-programming"
code: ../../../LeetCode/distinct_subsequences.cpp
---

[[Dynamic Programming]]

# Problem

Given two strings `s` and `t`, return _the number of distinct_ **_subsequences**  _of_ `s` _which equals_ `t`.
The test cases are generated so that the answer fits on a 32-bit signed integer.

# Solution

This problem is a variation of the [[Longest Common Subsequence]] question. Here since we have to match string `t` to a subsequence of `s`, we won't consider a case where we skip a letter of `t`. And to count the number of subsequences, we just add the cases where the characters match to the ones where we dont include that character.

unsigned long long int is used because the test cases get very large but the solution is under the int range so we have no issues returning int.

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