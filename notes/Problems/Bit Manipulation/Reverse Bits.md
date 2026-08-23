---
difficulty: Easy
topics:
  - Bit Manipulation
source: Leetcode
star: false
link: https://leetcode.com/problems/reverse-bits/
date: 2026-08-23
---

[[Bit Manipulation]]

# Problem
Reverse the bits of a given 32-bit unsigned integer.

# Approach
## Bit-by-Bit
For each of 32 iterations, read the lowest bit of `n` and place it into the mirrored position of the result. `while (t--)` runs with `t` taking values `31, 30, ..., 0` inside the loop body, and by the time `t` holds that value, `n` has already been right-shifted `31-t` times — so `n & 1` at that point reads original bit `(31-t)`. The assignment `ans`'s bit `t` = `n`'s bit `(31-t)` is exactly the definition of bit-reversal (`ans_j = n_{31-j}` for every `j`).

Worth using `uint32_t` rather than `int` for `ans`/`mask`: shifting a `1` into the sign bit (`1 << 31` on a signed `int`) is undefined behavior pre-C++20. It happens to produce the correct final bit pattern on every mainstream compiler (all use two's complement, and the final `uint32_t` return correctly reinterprets the bits either way), but it's relying on implementation behavior rather than guaranteed behavior — and this problem is inherently about raw bit patterns, so the unsigned type is also just the more correct fit.

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
- Time: $O(32) = O(1)$
- Space: $O(1)$

## Divide and Conquer (Better Constant Factor)
Since $32 = 2^5$, reversing can be done in exactly 5 fixed steps instead of 32 loop iterations: swap the two 16-bit halves, then adjacent bytes within each half, then adjacent nibbles within each byte, then adjacent bit-pairs, then adjacent individual bits. Each step operates on the whole word at once via masks, rather than one bit per iteration.

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
- Time: $O(1)$ — 5 fixed steps regardless of input, smaller constant than the bit-by-bit loop
- Space: $O(1)$
