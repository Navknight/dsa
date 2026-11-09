---
link: https://leetcode.com/problems/permutation-in-string/
difficulty: Medium
topics:
  - "[[Sliding Window]]"
  - "[[Hash Maps]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery: green
review: 2026-11-16
insight: "fixed window of |s1| over s2, compare 26-count arrays"
time: "O(n)"
space: "O(1)"
date: 2026-05-20
---

# Problem
Does `s2` contain a permutation of `s1`?

# Approach
## Fixed Window + Count Arrays
Window of size `|s1|` over `s2`. Compare the two count arrays with `==` on `vector<int>`.

- Slide by adding `s2[i]` and removing `s2[i-m]`. A variable window that shrinks on excess count also works, fixed is simpler

### Mistakes
- `memcmp` failed on NeetCode, missing `<cstring>`. `vector<int>` or `array<int,26>` with `==` needs no header

### Code
```cpp
bool checkInclusion(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    if (n < m)
        return false;
    vector<int> freq(26), window(26);

    for (char c : s1)
        freq[c - 'a']++;

    for (int i = 0; i < m; i++)
        window[s2[i] - 'a']++;

    for (int i = m; i < n; i++) {
        if (freq == window)
            return true;

        window[s2[i - m] - 'a']--;
        window[s2[i] - 'a']++;
    }

    return freq == window;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
