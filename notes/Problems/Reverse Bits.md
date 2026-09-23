---
link: https://leetcode.com/problems/reverse-bits/
difficulty: Easy
topics:
  - "[[Bit Manipulation]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "32 times: ans = (ans << 1) | (n & 1), n >>= 1"
time: "O(1)"
space: "O(1)"
date: 2026-08-23
---

# Problem
Reverse the bits of a 32-bit unsigned int.

# Approach
## Bit by Bit
Bit `t` of the answer = bit `31 - t` of `n`. Use `uint32_t`, `1 << 31` on a signed int is UB before C++20.

### Code
```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int t = 32;
        uint32_t ans = 0;
        while (t--) {
            uint32_t b = n & 1;
            if (b == 1) {
                uint32_t mask = 1u << t;
                ans = ans | mask;
            }
            n = n >> 1;
        }
        return ans;
    }
};
```

### Complexity
- Time: $O(1)$
- Space: $O(1)$

## Divide and Conquer
Swap 16-bit halves, then bytes, nibbles, pairs, bits. 5 masked steps.

### Code
```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
        n = ((n & 0xFF00FF00) >> 8)  | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xF0F0F0F0) >> 4)  | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xCCCCCCCC) >> 2)  | ((n & 0x33333333) << 2);
        n = ((n & 0xAAAAAAAA) >> 1)  | ((n & 0x55555555) << 1);
        return n;
    }
};
```

### Complexity
- Time: $O(1)$
- Space: $O(1)$
