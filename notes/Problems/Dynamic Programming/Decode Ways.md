---
difficulty: Medium
topics:
  - Dynamic Programming
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/decode-ways/
date: 2026-08-22
---

[[Dynamic Programming]] [[Recursion]]

# Problem
A string of digits maps to letters `A`–`Z` via `1`–`26`. Given a digit string `s`, count the number of ways it can be decoded. `'0'` can never stand alone as a letter — it's only valid as the second digit of `"10"` or `"20"`.

# Approach
1D DP: `ways(i)` = number of ways to decode the suffix `s[i:]`. At each position, two options: decode `s[i]` alone (valid iff `s[i] != '0'`), or decode `s[i..i+1]` together (valid iff that two-digit number is in `10..26`). `ways(i) = (single valid ? ways(i+1) : 0) + (double valid ? ways(i+2) : 0)`, base case `ways(n) = 1` (empty suffix — one way, do nothing).

## Backtracking (buggy first attempts)
First attempt returned `0` for the base case instead of `1`, and called the recursive branches *unconditionally* regardless of whether the single/double-digit check passed — so it ended up tallying every locally-valid segment encountered during an unconstrained traversal, rather than counting complete valid decodings. Traced on `"12"` (expected `2`): returned `3`.

Fixed by making each recursive call conditional on its branch's validity, and returning `1` from the base case (reaching the end successfully is what makes a path count at all):

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

This is correct but exponential — the same `start` gets reached through multiple different paths (e.g. two single-digit steps vs one double-digit step), and each one re-explores the whole remaining recursion from scratch.

### Complexity
- Time: $O(2^n)$ worst case
- Space: $O(n)$ recursion stack

## Top-Down Memoization
Cache each `start`'s result. Using `unordered_map` with `find()` as the "already computed" check sidesteps the sentinel-value problem hit in [[House Robber]] entirely — checking key *existence* rather than comparing against a magic value means there's no ambiguity even though `numDecodings` can legitimately be `0` (e.g. `s = "0"`).

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
- Time: $O(n)$ — each of the `n` states computed once
- Space: $O(n)$ for the map, plus $O(n)$ recursion stack

## O(1) Space (Optimal)
Same recurrence, computed backward with two rolling variables (`next1 = ways(i+1)`, `next2 = ways(i+2)`) instead of a map and recursion.

Verified on `"2260"`: the trailing `'0'` can't stand alone (`num > 0` fails) and its only pairing, `"60"`, is out of range (`> 26`), so that position resolves to `0` — and since every earlier position's count is built from `next1`/`next2` derived from it, the `0` propagates backward through the whole string with no special-casing needed, correctly returning `0`.

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

Worth knowing: `s.size()` returns an unsigned `size_t`, so `s.size() - 2` underflows to a huge number whenever `s.size() < 2` (i.e. a single-character string) — `i <= s.size() - 2` then evaluates `true` when it should be `false`. This never actually produces a wrong answer here, purely by luck: the resulting `substr` call clamps to whatever's left (a single digit, `0`-`9`), and any single digit fails the `num > 9` check anyway — so the branch is entered but always contributes nothing. Still fragile relative to the character-arithmetic version (`(s[i]-'0')*10 + (s[i+1]-'0')`), which never underflows since it doesn't rely on unsigned size arithmetic in the same way.

### Complexity
- Time: $O(n)$
- Space: $O(1)$
