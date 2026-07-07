---
difficulty: Medium
topics:
  - Backtracking
  - Strings
source: Leetcode
star: false
link: https://leetcode.com/problems/generate-parentheses/
date: 2026-06-30
---

[[Backtracking]] [[Strings]]

# Problem
Given `n`, generate all combinations of `n` pairs of valid parentheses.

# Approach
## Backtracking with Open/Close Counts
Track `l` (open count) and `r` (close count). At each step try adding `(` or `)`. Prune invalid states: `l > n`, `r > n`, `r > l` (close before open). Push when `l == r == n`.

### Code
```cpp
void solve(vector<string>& ans, string& s, int l, int r, int n) {
    if (l == n && l == r) { ans.push_back(s); return; }
    if (l > n || r > n || r > l) return;

    s += "(";
    solve(ans, s, l+1, r, n);
    s.pop_back();
    s += ")";
    solve(ans, s, l, r+1, n);
    s.pop_back();
}

vector<string> generateParenthesis(int n) {
    string s = "(";
    vector<string> ans;
    solve(ans, s, 1, 0, n);
    return ans;
}
```

### Complexity
- Time: $O(4^n / \sqrt{n})$ — Catalan number of valid sequences
- Space: $O(n)$ recursion depth
