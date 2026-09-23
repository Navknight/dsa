---
link: https://leetcode.com/problems/generate-parentheses/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "add ( while open < n, add ) while close < open"
time: "O(4^n / √n)"
space: "O(n)"
date: 2026-06-30
---

# Problem
All valid combinations of `n` pairs of parentheses.

# Approach
## Backtracking with Counts
Track open `l` and close `r`. Prune `l > n` or `r > l`. Push when `l == r == n`.

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
- Time: $O(4^n / \sqrt{n})$, Catalan
- Space: $O(n)$
