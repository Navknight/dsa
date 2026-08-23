---
difficulty: Medium
topics:
  - Two Pointers
  - Strings
source: Leetcode
star: false
link: https://leetcode.com/problems/longest-palindromic-substring/
date: 2026-08-22
---

[[Two Pointers]] [[Strings]]

# Problem
Given a string `s`, return the longest palindromic substring in `s`.

# Approach
## Expand Around Center
A palindrome is symmetric around a center — every substring has exactly one center, either a single character (odd length) or the gap between two characters (even length). So instead of checking every substring directly, expand outward from each of the `2n-1` possible centers while characters match on both sides.

One helper does both cases: `expand(s, i, i)` treats index `i` itself as an odd-length center, `expand(s, i, i+1)` treats the gap after `i` as an even-length center. The loop only tracks indices (`start`, `maxl`) while scanning — the actual `substr` allocation happens exactly once, at the end, instead of on every improvement.

Originally filed under Sliding Window (`notes/Problems/Sliding Window/Longest Palindromic Sibstring.md`) — moved here since the actual pattern is Two Pointers / Expand Around Center, not a sliding window (there's no single window that only grows/shrinks from one side under a constraint; each center's expansion is independent and symmetric).

### Code
```cpp
class Solution {
public:
    int expand(string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        int maxl = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            int even = expand(s, i, i + 1);
            int odd = expand(s, i, i);

            int len = max(even, odd);
            if (len > maxl) {
                maxl = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxl);
    }
};
```

### Complexity
- Time: $O(n^2)$ — up to $O(n)$ centers, each expansion up to $O(n)$
- Space: $O(1)$ extra (excluding the output substring)
