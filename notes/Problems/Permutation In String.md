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
mastery:
review:
insight: "fixed window of |s1| over s2, compare 26-count arrays"
time: "O(n)"
space: "O(1)"
date: 2026-05-20
---

# Problem
Does `s2` contain a permutation of `s1`?

# Approach
## Fixed Window + Count Arrays
Window of size `|s1|` over `s2`. Compare the two count arrays with `memcmp`.

### Code
```cpp
bool checkInclusion(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    if (n < m)
        return false;
    int freq[26] = {}, window[26] = {};

    for (char s : s1) {
        freq[s - 'a']++;
    }

    for (int i = 0; i < m; i++) {
        window[s2[i] - 'a']++;
    }

    for (int i = m; i < n; i++) {
        if (memcmp(freq, window, sizeof(freq)) == 0)
            return true;

        window[s2[i - m] - 'a']--;
        window[s2[i] - 'a']++;
    }

    return memcmp(freq, window, sizeof(freq)) == 0;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
