---
link: https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
  - "[[Strings]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "MCM on the string: 0 if already a palindrome, else min over k of 1 + left + right"
time: "O(n³)"
space: "O(n²)"
date: 2023-08-10
---

# Problem
Min cuts so every part is a palindrome. Same as LC Palindrome Partitioning II.

# Approach
## MCM Style
`pal(i, j)` = 0 if `s[i..j]` is a palindrome. Else try every cut `k`: `1 + pal(i, k) + pal(k+1, j)`. Memo on `(i, j)`. Precomputing palindromes like in [[Palindrome Partitioning]] drops the check to O(1).

### Code
```cpp
bool isPalindrome(string str)
{
    int n = str.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }

    return true;
}

int pal(int i, int j, string str, vector<vector<int>> &t)
{
    if (i >= j)
        return t[i][j] = 0;
    if (isPalindrome(str.substr(i, j - i + 1)))
        return t[i][j] = 0;
    if (t[i][j] != -1)
        return t[i][j];
    else
    {
        int mini = INT32_MAX;
        for (int k = i; k < j; k++)
        {
            int left = (t[i][k] != -1) ? t[i][k] : pal(i, k, str, t);
            int right = (t[k + 1][j] != -1) ? t[k + 1][j] : pal(k + 1, j, str, t);
            int temp = 1 + right + left;
            mini = min(mini, temp);
        }
        return t[i][j] = mini;
    }
}

int palindromicPartition(string str)
{
    int n = str.size();
    vector<vector<int>> t(n + 1, vector<int>(n + 1, -1));
    return pal(0, n - 1, str, t);
}
```

### Complexity
- Time: $O(n^3)$
- Space: $O(n^2)$
