---
link: https://leetcode.com/problems/decode-ways/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery: red
review: 2026-11-09
insight: "ways(i) = ways(i+1) if s[i] != '0' + ways(i+2) if 10..26. base ways(n) = 1"
time: "O(n)"
space: "O(1)"
date: 2026-08-22
---

# Problem
Digits map to `A-Z` via `1-26`. Count decodings. `'0'` can't stand alone.

# Approach
`ways(i) = (s[i] != '0' ? ways(i+1) : 0) + (10 <= s[i..i+1] <= 26 ? ways(i+2) : 0)`, `ways(n) = 1`.

## Backtracking
Mistakes I made: base case returned 0 instead of 1, and recursed without checking validity. `"12"` gave 3.

### Code
```cpp
int backtrack(string& s, int start) {
    if (start >= s.size())
        return 1;

    int num = stoi(s.substr(start, 1));
    int count = 0;
    if (num > 0) {
        count += backtrack(s, start + 1);
    }

    if (start <= s.size() - 2) {
        num = stoi(s.substr(start, 2));
        if (num > 9 && num <= 26) {
            count += backtrack(s, start + 2);
        }
    }

    return count;
}
```

### Complexity
- Time: $O(2^n)$
- Space: $O(n)$

## Memoization
Map keyed on `start`. `find()` avoids a sentinel since 0 is a valid answer.

### Code
```cpp
class Solution {
public:
    unordered_map<int, int> mp;
    int backtrack(string& s, int start) {
        if (start >= s.size())
            return 1;
        if (mp.find(start) != mp.end())
            return mp[start];

        int num = stoi(s.substr(start, 1));
        int count = 0;
        if (num > 0) {
            count += backtrack(s, start + 1);
        }

        if (start <= s.size() - 2) {
            num = stoi(s.substr(start, 2));
            if (num > 9 && num <= 26) {
                count += backtrack(s, start + 2);
            }
        }

        return mp[start] = count;
    }

    int numDecodings(string s) { return backtrack(s, 0); }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Two Variables
Same recurrence backwards with `next1`, `next2`.

Trap: `s.size() - 2` underflows for size 1. Harmless here, single digits fail `num > 9`.

### Code
```cpp
class Solution {
public:
    int numDecodings(string s) {
        int next1 = 1;
        int next2 = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int curr = 0;
            if (s[i] - '0' > 0) {
                curr += next1;
            }

            if (i <= s.size() - 2) {
                int num = stoi(s.substr(i, 2));
                if (num > 9 && num <= 26) {
                    curr += next2;
                }
            }

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

- A `'0'` digit has 0 ways. Do not copy `dp[i+1]` into it
- Two digits need 10..26. Skipping the `'0'` start already gives the lower bound
- `dp(n + 1)` with `dp[n] = 1` removes the last-char special case and the `i + 2 < n` guard
- Tests: `226` is 3, `10` is 1, `100` is 0, `2101` is 1, `1111` is 5
- O(1) space: `next`, `next2`, shift before overwrite

### Mistakes
- Read `dp` where I meant `s`. `dp[i] != '0'` instead of `s[i] != '0'`
- Counting DP adds `dp` values, never a `+ 1` constant. The `+ 1` only works near the end of the string
