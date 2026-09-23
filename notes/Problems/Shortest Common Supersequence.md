---
link: https://leetcode.com/problems/shortest-common-supersequence/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "LCS table, walk back: match adds the char once, else add the char from the side you move away from"
time: "O(n * m)"
space: "O(n * m)"
date: 2023-07-24
---

# Problem
Shortest string with both `a` and `b` as subsequences.

# Approach
## Backtrack the LCS Table
Like [[Print LCS]], but on a mismatch still add the char you step past. Prepend whatever is left of the unfinished string. Length = `n + m - lcs`.

### Code
```cpp
// string scs(int n, int m, string a, string b)
// {
//     if (n == 0 || m == 0)
//         return (n == 0) ? b.substr(0, m) : a.substr(0, n);
//     else
//     {
//         if (a[n - 1] == b[m - 1])
//             return scs(n - 1, m - 1, a, b) + a[n - 1];
//         else
//         {
//             string x = scs(n - 1, m, a, b) + a[n - 1];
//             string y = scs(n, m - 1, a, b) + b[m - 1];
//             return (x.size() < y.size()) ? x : y;
//         }
//     }
// }

string scs(int n, int m, string a, string b)
{
    vector<vector<int>> t(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (a[i - 1] == b[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string ans = "";
    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans = a[i - 1] + ans;
            i--;
            j--;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
            {
                ans = a[i - 1] + ans;
                i--;
            }
            else
            {
                ans = b[j - 1] + ans;
                j--;
            }
        }
    }
    ans = ((i == 0) ? b.substr(0, j) : a.substr(0, i)) + ans;

    return ans;
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n \cdot m)$
