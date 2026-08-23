---
difficulty: Medium
topics:
  - Dynamic Programming
  - Recursion
  - BFS
source: Leetcode
star: false
link: https://leetcode.com/problems/word-break/
code: LeetCode/word_break.cpp
date: 2026-08-22
---

[[LeetCode/word_break.cpp]]
[[Dynamic Programming]] [[Recursion]] [[BFS]]

# Problem
Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words. Words may be reused.

# Approach
Think of it as reachability: position `i` is reachable if some earlier reachable position `j` has `s[j..i-1]` as an actual dictionary word. The string is breakable iff the very end is reachable.

## Top-Down Memoization
`solve(start)` = can `s[start:]` be segmented. Loop over `wordDict` directly instead of trying every possible substring length at `start` — this skips lengths that couldn't possibly match any word at all, rather than testing every length from `1` up to the remaining length. Memoize on `start` with `unordered_map<int,bool>`, using `find()` for existence-checking rather than a magic sentinel value (same reasoning as [[House Robber]] and [[Decode Ways]] — a legitimate answer here can be either `true` or `false`, so there's no safe unused sentinel to compare against directly).

Still $O(|wordDict|)$ work per state since it's a linear scan through the dictionary rather than a hash lookup — fine given LeetCode's constraints (`wordDict.length <= 1000`), but the fully optimized version would combine an `unordered_set` for $O(1)$ membership with only trying the handful of distinct word-lengths actually present in the dictionary.

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
- Time: $O(n \times |wordDict| \times L)$ where $L$ is average word length (the `substr`/compare cost)
- Space: $O(n)$ for the memo, plus $O(n)$ recursion stack

## Bottom-Up DP
`dp[i]` = can `s[0..i-1]` be segmented. `dp[0] = true` (empty prefix, trivially segmentable). Fill `i` from `1` to `n` — this direction works cleanly since `dp[i]` only ever depends on `dp[j]` for `j < i`, always already computed by the time it's needed (unlike the palindrome DP table, which needs inner ranges filled before outer ones).

For each `i`, scan every split point `j < i`: if `dp[j]` is true and `s[j..i-1]` is in the dictionary, `dp[i]` is true — no need to check further splits once one works.

```
dp[0]=T  dp[1]  dp[2]  dp[3]  dp[4]=T  ...  dp[n]
  |________________________|
   "leet" found here -> dp[4] becomes reachable
```

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
- Time: $O(n^2)$ (the `i, j` double loop), $O(1)$ average dictionary lookup via the `unordered_set`
- Space: $O(n)$ for `dp`, plus $O(\sum |\text{word}|)$ for the set

## BFS (Level-by-Level Reachability)
Same reachability idea as the DP versions, framed as BFS: each reachable index is a node, `seen[]` tracks visited indices, and every dictionary word found from the current index enqueues the new position. Reaching `s.length()` returns `true`.

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
- Time: $O(n^2)$ — each index enqueued once, each with up to $O(n)$ substring checks
- Space: $O(n)$ for `seen` and the queue, plus $O(\sum |\text{word}|)$ for the set
