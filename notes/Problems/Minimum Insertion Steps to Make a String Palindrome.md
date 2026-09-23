---
link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "n - LCS(s, reverse(s)), the LCS with its reverse is the longest palindromic subsequence"
time: "O(n²)"
space: "O(n²)"
date: 2023-07-27
---

# Problem
Min insertions to make `s` a palindrome.

# Approach
## LCS with the Reverse
[[Longest Common Subsequence]] of `s` and `reverse(s)` = longest palindromic subsequence. Everything else needs a partner inserted: `n - lps`.

Typo in my code: `t[i][j] == 0` instead of `=`. Harmless because the vector starts at 0.

### Code
```cpp
int minInsertions(string s)
{
    int n = s.size();
    string sr = "";

    for (int i = 0; i < n; i++)
    {
        sr = s[i] + sr;
    }

    vector<vector<int>> t(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] == 0;
            else
            {
                if (s[i - 1] == sr[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return n - t[n][n];
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n^2)$
