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
mastery: red
review: 2026-11-11
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

- `dp[i]` = the first `i` chars split completely into words. `dp[0]` is the empty prefix, so a word at the start needs no special case
- Cap `j` at `i - maxLen`, `maxLen` = longest word. About `O(n * L^2)` instead of `O(n^3)`
- Or loop over the words: `len <= i && dp[i - len] && s.compare(i - len, len, w) == 0`. No `substr` allocation

### Mistakes
- Thought two pointers (a window `[l, r]`). A break chosen now can be wrong later, a window can't undo it. It is DP over prefixes
- Set `dp[0]` as "first char is in the dict". It is true, the empty prefix
- First draft had no inner `j` loop and never read `dp[j]`
- Inner loop incremented `i++` instead of `j++`
- `substr(j, i - j + 1)` is one char too long, `substr` takes a length
- Scanned the vector for every lookup instead of using the `unordered_set`

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
