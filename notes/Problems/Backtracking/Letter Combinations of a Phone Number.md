---
difficulty: Medium
topics:
  - Backtracking
  - Strings
source: Leetcode
star: false
link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
date: 2026-06-30
---

[[Backtracking]] [[Strings]]

# Problem
Given a string of digits 2-9, return all possible letter combinations that the number could represent (phone keypad mapping).

# Approach
## Backtracking with Digit Map
Map each digit to its letters. At each index, iterate letters for current digit, append, recurse, pop.

Trap: `digits[idx] - '0'` to convert char to int, not `stoi(digits[idx])` (takes string not char) and not `digits[idx] = '0'` (assignment corrupts string).

Edge case: empty input returns empty vector, not `[""]`.

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
- Time: $O(4^n)$ where $n$ = digits length (max 4 letters per digit)
- Space: $O(n)$ recursion depth
