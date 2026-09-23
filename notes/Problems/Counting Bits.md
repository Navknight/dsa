---
link: https://leetcode.com/problems/counting-bits/
difficulty: Easy
topics:
  - "[[Bit Manipulation]]"
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "ans[i] = ans[i >> 1] + (i & 1)"
time: "O(n)"
space: "O(n)"
date: 2026-08-23
---

# Problem
Number of set bits for every `i` in `0..n`.

# Approach
## Per Number
Shift-and-check loop from [[Number of 1 Bits]] for each `i`.

### Code
```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int t = 32;
            int curr = i;
            ans.push_back(0);
            while (t--) {
                int c = curr & 1;
                curr = curr >> 1;
                ans[i] += c;
            }
        }
        return ans;
    }
};
```

### Complexity
- Time: $O(32n)$
- Space: $O(n)$

## DP
`i >> 1` is smaller and already computed, `i & 1` is the dropped bit.

### Code
```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
