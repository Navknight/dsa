---
difficulty: Medium
topics:
  - Two Pointers
  - Strings
source: Leetcode
star: false
link: https://leetcode.com/problems/palindromic-substrings/
date: 2026-08-22
---

[[Two Pointers]] [[Strings]] [[Longest Palindromic Substring]]

# Problem
Given a string `s`, return the number of palindromic substrings in it (counting distinct occurrences by position, not distinct values).

# Approach
## Expand Around Center
Same mechanics as [[Longest Palindromic Substring]] — expand outward from each of the `2n-1` centers (odd: single index, even: gap between two indices) while characters match on both sides. The difference is what gets tracked: instead of remembering the longest palindrome found, every successful expansion step *is itself* one palindromic substring, so a simple counter incremented once per iteration counts all of them. The odd loop's very first iteration (`l==r`) is always the trivial single-character palindrome, so it's counted for free without a separate base case.

Not DP — no subproblem results are stored or reused between centers; each expansion runs independently. The genuine DP formulation for this problem is the same 2D interval-DP table as Longest Palindromic Substring (`dp[i][j] = s[i]==s[j] && dp[i+1][j-1]`, counting every `true` cell instead of tracking the longest), which is 2D DP, not 1D — the recurrence needs both endpoints `i` and `j`, so it can't collapse to a single index like House Robber or Climbing Stairs can.

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
- Time: $O(n^2)$ — worst case all-same-character (e.g. `"aaaa"`), where every center expands the full remaining length
- Space: $O(1)$ extra
