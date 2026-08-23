---
difficulty: Medium
topics:
  - Bit Manipulation
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/sum-of-two-integers/
date: 2026-08-23
---

[[Bit Manipulation]] [[Recursion]]

# Problem
Calculate the sum of two integers `a` and `b` without using the `+` or `-` operators.

# Approach
Core idea: `a ^ b` gives the sum of `a` and `b` ignoring carries, and `a & b` gives exactly the bit positions where a carry is generated (shifted left by 1 to land in the correct position for the next addition). Repeat until no carry remains.

## Iterative
### Code
```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
```

Worth knowing: `(a & b) << 1` on a plain signed `int` is undefined behavior if `a & b` has its top bit (bit 31) set — e.g. `a = b = INT_MIN` — since left-shifting a value that overflows a signed type isn't well-defined pre-C++20. Casting to `unsigned int` before shifting makes it well-defined (unsigned overflow wraps modulo $2^{32}$, which is exactly the truncate-to-32-bits behavior this algorithm wants anyway).

### Complexity
- Time: $O(32) = O(1)$ — at most 32 carry-propagation steps
- Space: $O(1)$

## Recursive
Same algorithm, tail-recursive instead of looped.

Bug hit exploring this direction: an attempt to fold sum and carry into one combined `do-while` (`sum = a^b^carry; carry = (a&b&carry)<<1;`) is a different, broken formula — `carry` starts at `0`, so `a & b & carry` is always `0` on the first pass, meaning the loop can never run more than once and just computes `a^b` (only correct when `a`,`b` share no set bits at all). Traced on `a=2,b=3` (expected `5`): returned `1`. The real recurrence needs `a^b` and `(a&b)<<1` to feed into the *next* call's `a` and `b` respectively, not to be combined with a stale carry in a single expression.

### Code
```cpp
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        return getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};
```

Same signed-shift caveat as the iterative version, fixed the same way. Also technically $O(32)$ recursion stack (no guaranteed tail-call elimination in C++, same caveat as [[Climbing Stairs]]/[[House Robber]]) — trivial here since it's bounded by a small constant regardless.

### Complexity
- Time: $O(32) = O(1)$
- Space: $O(32) = O(1)$ recursion stack

## Bit-by-Bit Full Adder
Alternative direction: simulate a hardware ripple-carry adder, processing one bit position at a time with an explicit carry-in, rather than the whole-word XOR/AND-shift trick above.

`carry` must come from the *majority* of `bitA`, `bitB`, and the *previous* carry (`(bitA & bitB) | (bitB & carry) | (bitA & carry)`), not from ANDing all three raw multi-bit words together — that was the mistake in the broken `do-while` attempt above, generalized: majority logic needs single-bit values feeding into it, computed fresh at each bit position via `(a >> i) & 1`.

### Code
```cpp
class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int sumBit = bitA ^ bitB ^ carry;
            carry = (bitA & bitB) | (bitB & carry) | (bitA & carry);
            result |= (sumBit << i);
        }
        return result;
    }
};
```

No signed-shift UB concern here: `carry` is always `0` or `1`, and `sumBit << i` for `i < 32` shifting a `0`/`1` value never touches the sign-bit-overflow scenario the whole-word approach could hit.

### Complexity
- Time: $O(32) = O(1)$
- Space: $O(1)$
