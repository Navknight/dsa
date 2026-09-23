---
link: https://leetcode.com/problems/longest-palindromic-substring/
difficulty: Medium
topics:
  - "[[Two Pointers]]"
  - "[[Strings]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "expand around all 2n-1 centers, odd (i, i) and even (i, i+1)"
time: "O(n²)"
space: "O(1)"
date: 2026-08-22
---

# Problem
Longest palindromic substring.

# Approach
## Expand Around Center
Every palindrome has one center, a char or a gap. Expand from each, track `start` and `maxl`, `substr` once at the end.

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
- Time: $O(n^2)$
- Space: $O(1)$
