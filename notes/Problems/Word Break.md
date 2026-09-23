---
link: https://leetcode.com/problems/word-break/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
  - "[[BFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "dp[i] = some j < i with dp[j] and s[j..i) in the dict"
time: "O(n²)"
space: "O(n)"
date: 2026-08-22
---

# Problem
Can `s` be split into dictionary words (reuse allowed)?

# Approach
Reachability: index `i` is reachable if some reachable `j` has `s[j..i)` in the dict.

## Memoization
`solve(start)` loops over the dict words. Memo with `find()`, true and false are both real answers.

### Code
```cpp
class Solution {
public:
    unordered_map<int, bool> mp;
    bool solve(string& s, vector<string>& wordDict, int start) {
        if (start >= s.size()) return true;
        if (mp.find(start) != mp.end()) return mp[start];
        for (auto str : wordDict) {
            if (str.size() <= s.size() - start && str == s.substr(start, str.size()) && solve(s, wordDict, start + str.size()))
                return mp[start] = true;
        }

        return mp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) { return solve(s, wordDict, 0); }
};
```

### Complexity
- Time: $O(n \cdot |dict| \cdot L)$
- Space: $O(n)$

## Tabulation
`dp[0] = true`. For each `i`, any `j` with `dp[j]` and `s[j..i)` in a set.

### Code
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$

## BFS
Indices are nodes, a matching word is an edge. Reaching `n` means true.

### Code
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> seen(s.length(), false);
        q.push(0);

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            if (start == s.length()) {
                return true;
            }

            for (int end = start + 1; end <= s.length(); end++) {
                if (seen[end]) {
                    continue;
                }

                if (words.find(s.substr(start, end - start)) != words.end()) {
                    q.push(end);
                    seen[end] = true;
                }
            }
        }

        return false;
    }
};
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$
