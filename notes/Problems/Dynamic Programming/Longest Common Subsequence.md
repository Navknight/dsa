---
difficulty: Medium
topics:
  - Dynamic Programming
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/longest-common-subsequence/
date: 2026-08-23
---

[[Dynamic Programming]] [[Recursion]]

# Problem
Given two strings `text1` and `text2`, return the length of their longest common subsequence (not necessarily contiguous, order-preserving in both strings).

# Approach
2D DP: state is `(i,j)`, one index per string — a single index into just one string can't capture "how far along both strings have matched." If the current characters match, always take them (never optimal to skip a match — an exchange argument shows any LCS not using an available matching pair can be rearranged to use it without losing length). If they don't match, try skipping a character from either string and take the max.

## Top-Down Memoization
Bugs hit along the way, both worth remembering:
- First attempt threaded an accumulator (`len`) through the recursion, adding to it at each match and returning it directly from the base case, while memoizing purely on `(start1, start2)`. This breaks memoization's core requirement — the cached value must be a pure function of the state alone, but baking a path-dependent running total into the return value means the cache captures whatever `len` the *first* caller happened to arrive with, and any later caller reaching the same `(start1,start2)` with a *different* accumulated `len` gets back a stale, wrong baseline. Fixed by having `solve` return only "LCS length achievable from here onward" (independent of path), adding `1` at the match site (`take = 1 + solve(...)`) instead of threading a counter.
- `unordered_map<pair<int,int>, int>` doesn't compile out of the box — `std::pair` has no default `std::hash` specialization in standard C++. Switched to `map<pair<int,int>,int>`, which works because `std::pair` does have a default `operator<`. Trade-off: $O(\log(\text{states}))$ per access instead of $O(1)$.
- `0` as the memo's "not yet computed" sentinel is unsafe here too — a legitimate LCS length can be `0` (e.g. two strings with no characters in common at all). Traced on completely disjoint-character strings: every state's true answer is `0`, so a `0`-sentinel check never once short-circuits, collapsing back into full exponential recomputation despite memoization being "in place." `-1` is the safe sentinel (same reasoning as [[House Robber]] and [[Word Break]]).

### Code
```cpp
class Solution {
public:
    map<pair<int, int>, int> mp;
    int solve(string& t1, string& t2, int start1, int start2) {
        if (start1 == t1.size() || start2 == t2.size()) return 0;
        if (mp.find({start1, start2}) != mp.end()) return mp[{start1, start2}];
        int take = 0, one = 0, second = 0;

        if (t1[start1] == t2[start2]) {
            take = 1 + solve(t1, t2, start1 + 1, start2 + 1);
        } else {
            one = solve(t1, t2, start1 + 1, start2);
            second = solve(t1, t2, start1, start2 + 1);
        }

        return mp[{start1, start2}] = max({one, second, take});
    }

    int longestCommonSubsequence(string text1, string text2) { return solve(text1, text2, 0, 0); }
};
```

### Complexity
- Time: $O(mn \log(mn))$ — the `log` factor from `map`; a 2D array keyed directly by `(start1,start2)` would give true $O(mn)$
- Space: $O(mn)$ for the map, plus $O(m+n)$ recursion stack

## Bottom-Up DP (2D Table)
`dp[i][j]` = LCS length of `text1[0..i-1]` and `text2[0..j-1]` (1-indexed table over 0-indexed strings). Base case `dp[0][j] = dp[i][0] = 0` — an empty prefix shares zero characters with anything (unlike Unique Paths' edge cells, which were `1`; here there's nothing to match against an empty string, so the trivial value is `0`, not `1`).

Bug hit along the way: comparing `text1[i]`/`text2[j]` instead of `text1[i-1]`/`text2[j-1]`. Since `dp[i][j]` represents length-`i`/length-`j` prefixes, the character at "position `i`" is string index `i-1`. Traced on `t1="xa", t2="ya"` (expected `1`, just `"a"`): the shifted version never compares either string's real first character to anything, and at the final cell `text1[n1]`/`text2[n2]` both read one past their string's end — legal in C++11+, returning the trailing `'\0'` — so those two *always* "match" regardless of actual content, silently injecting a fabricated `+1` at the corner. Buggy version returned `2`; fixed version correctly returns `1`.

### Code
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};
```

### Complexity
- Time: $O(mn)$
- Space: $O(mn)$
