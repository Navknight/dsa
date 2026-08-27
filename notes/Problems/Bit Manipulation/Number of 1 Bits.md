---
difficulty: Easy
topics:
  - Bit Manipulation
source: Leetcode
star: false
link: https://leetcode.com/problems/number-of-1-bits/
date: 2026-08-23
---

[[Bit Manipulation]]

# Problem
Given a 32-bit unsigned integer `n`, return the number of `1` bits it has (Hamming weight).

# Approach
## Check-and-Shift
Check the lowest bit with `n & 1`, add it to the count, then shift `n` right by one to bring the next bit into position. Repeat 32 times (fixed width).

Bug hit along the way: `n >>= n` instead of `n >>= 1` — shifts `n` right by its own current value rather than by one position. Traced on `n=5` (binary `101`, expected `2`): after the first iteration `n` becomes `5 >> 5 = 0` immediately, and every subsequent shift is a no-op (`0 >> 0 = 0`), so all remaining bits are silently skipped. Buggy version returned `1` instead of `2`.

### Code
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int t = 32;
        int count = 0;
        while (t--) {
            int c = n & 1;
            count += c;
            n = n >> 1;
        }
        return count;
    }
};
```

### Complexity
- Time: $O(1)$ — always exactly 32 iterations for a fixed-width integer
- Space: $O(1)$
