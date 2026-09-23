---
link: https://leetcode.com/problems/palindrome-partitioning/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Strings]]"
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "at each index try every palindrome prefix, recurse on the rest"
time: "O(n * 2^n)"
space: "O(n²)"
date: 2026-06-30
---

# Problem
All ways to split `s` so every part is a palindrome.

# Approach
## Backtracking
At each index try every palindrome prefix, recurse on the rest.

### Code
```cpp
bool checkPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i <= n/2; i++)
        if (s[i] != s[n-i-1]) return false;
    return true;
}

void solve(vector<vector<string>>& ans, vector<string>& curr, string& s, int p) {
    if (p >= s.size()) { ans.push_back(curr); return; }
    for (int i = p; i < s.size(); i++) {
        int len = i - p + 1;
        if (checkPalindrome(s.substr(p, len))) {
            curr.push_back(s.substr(p, len));
            solve(ans, curr, s, i+1);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> curr;
    solve(ans, curr, s, 0);
    return ans;
}
```

### Complexity
- Time: $O(n \cdot 2^n)$
- Space: $O(n)$

## Backtracking + Precomputed Palindromes
`isPalin[i][j] = s[i] == s[j] && (j - i <= 2 || isPalin[i+1][j-1])`, O(1) checks.

### Code
```cpp
vector<vector<bool>> isPalin;

void precompute(string& s) {
    int n = s.size();
    isPalin.assign(n, vector<bool>(n, false));
    for (int i = n-1; i >= 0; i--)
        for (int j = i; j < n; j++)
            if (s[i] == s[j] && (j-i <= 2 || isPalin[i+1][j-1]))
                isPalin[i][j] = true;
}

void solve(vector<vector<string>>& ans, vector<string>& curr, string& s, int p) {
    if (p >= s.size()) { ans.push_back(curr); return; }
    for (int i = p; i < s.size(); i++) {
        if (isPalin[p][i]) {
            curr.push_back(s.substr(p, i-p+1));
            solve(ans, curr, s, i+1);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    precompute(s);
    vector<vector<string>> ans;
    vector<string> curr;
    solve(ans, curr, s, 0);
    return ans;
}
```

### Complexity
- Time: $O(n^2 + 2^n)$
- Space: $O(n^2)$
