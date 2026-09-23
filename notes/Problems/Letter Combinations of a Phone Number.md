---
link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "backtrack over digits, try every letter of the current digit"
time: "O(4^n)"
space: "O(n)"
date: 2026-06-30
---

# Problem
All letter combinations of a phone number.

# Approach
## Backtracking
Map digit to letters, append, recurse, pop.

Traps: `digits[idx] - '0'`, not `stoi`. Empty input returns `{}`, not `{""}`.

### Code
```cpp
unordered_map<int, string> mp = {{2,"abc"},{3,"def"},{4,"ghi"},
                                  {5,"jkl"},{6,"mno"},{7,"pqrs"},
                                  {8,"tuv"},{9,"wxyz"}};

void solve(vector<string>& ans, string& curr, string& digits, int idx) {
    if (idx == digits.size()) { ans.push_back(curr); return; }
    for (char c : mp[digits[idx] - '0']) {
        curr.push_back(c);
        solve(ans, curr, digits, idx+1);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans;
    string curr;
    solve(ans, curr, digits, 0);
    return ans;
}
```

### Complexity
- Time: $O(4^n)$
- Space: $O(n)$
