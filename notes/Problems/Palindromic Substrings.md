---
link: https://leetcode.com/problems/palindromic-substrings/
difficulty: Medium
topics:
  - "[[Two Pointers]]"
  - "[[Strings]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "expand around all 2n-1 centers, count every successful expansion"
time: "O(n²)"
space: "O(1)"
date: 2026-08-22
---

# Problem
Count palindromic substrings.

# Approach
## Expand Around Center
Same as [[Longest Palindromic Substring]], but every expansion step is one palindrome, so count it.

### Code
```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            // even
            int l = i;
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                count++;
            }

            // odd
            l = i;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                count++;
            }
        }

        return count;
    }
};
```

### Complexity
- Time: $O(n^2)$
- Space: $O(1)$
