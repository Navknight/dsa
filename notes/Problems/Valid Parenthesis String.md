---
link: https://leetcode.com/problems/valid-parenthesis-string/
difficulty: Medium
topics:
  - "[[Greedy]]"
  - "[[Dynamic Programming]]"
  - "[[Strings]]"
source: Leetcode
star: true
blind75: false
mastery: red
review: 2026-11-09
insight: "track the range [lo, hi] of possible open counts, * widens it, hi < 0 fails, floor lo at 0, answer lo == 0"
time: "O(n)"
space: "O(1)"
date: 2026-11-08
---

# Problem
`(`, `)` and `*` where `*` is `(`, `)` or empty. Can the string be valid?

# Approach
## Range of open counts (greedy)
One counter fails because `*` has 3 choices. Keep the range of possible open counts instead.
- `(`: lo+1, hi+1. `)`: lo-1, hi-1. `*`: lo-1, hi+1
- hi < 0 at any step: return false
- floor lo at 0 (a `*` can be empty instead of `)`)
- end: lo == 0

Not written yet. Re-solve this first, I did not fully understand why the range is enough.

- The true cells of each DP row are one contiguous run. lo and hi are its two ends, that is why the table is not needed

### Mistakes
- Single `open` counter, `*` as `)` when open > 0, is wrong. `(*)` and `(*))` come out false

## 2D DP
`dp[i][j]`: can `s[i..]` be completed given `j` unmatched `(` pending before `i`. Base `dp[n][0] = true`. Fill `i` from `n-1` down to 0.

- Table is position x pending opens, not opens x closes. Two counts lose the position, and the future only needs the difference
- Illegal `)` at `j == 0` is a pruned transition, not a floor. Flooring belongs to the lo/hi version
- Row `i` reads row `i+1`. Guard `j+1 <= n` and `j >= 1`

### Mistakes
- Read row `i` instead of row `i+1`
- Wrote `s[i] = '('` instead of `==`
- Forgot the base cell and the `return`

### Code
```cpp
bool checkValidString(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (s[i] == '(') {
                dp[i][j] = (j + 1 <= n) && dp[i + 1][j + 1];
            } else if (s[i] == ')') {
                dp[i][j] = (j >= 1) && dp[i + 1][j - 1];
            } else {
                dp[i][j] = dp[i + 1][j] || ((j >= 1) && dp[i + 1][j - 1]) ||
                           ((j + 1 <= n) && dp[i + 1][j + 1]);
            }
        }
    }
    return dp[0][0];
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n^2)$
