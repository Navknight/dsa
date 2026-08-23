---
difficulty: Easy
topics:
  - Bit Manipulation
  - Dynamic Programming
source: Leetcode
star: false
link: https://leetcode.com/problems/counting-bits/
date: 2026-08-23
---

[[Bit Manipulation]] [[Dynamic Programming]] [[Number of 1 Bits]]

# Problem
Given an integer `n`, return an array `ans` of length `n+1` where `ans[i]` is the number of `1` bits in `i`, for every `i` from `0` to `n`.

# Approach
## Per-Number Bit Count
Reuse the check-and-shift loop from [[Number of 1 Bits]] independently for every `i` from `0` to `n`.

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
- Time: $O(n \times 32) = O(n)$ — 32 is a constant
- Space: $O(n)$ for the output

## DP (O(1) per element)
`countBits(i)` can be derived from an already-computed smaller answer instead of recounting from scratch: `i >> 1` drops the lowest bit of `i`, and `i & 1` tells you whether that dropped bit was a `1`. Since `i >> 1 < i` for any `i >= 1`, `ans[i >> 1]` is always already computed by the time `i` is processed (increasing order) — this is 1D DP, state `i` depending on the single earlier state `i >> 1`.

Same total $O(n)$ time as the per-number approach, but each element costs $O(1)$ instead of a fixed 32 iterations — better constant factor, same asymptotic class.

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
