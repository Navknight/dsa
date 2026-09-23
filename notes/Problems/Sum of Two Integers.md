---
link: https://leetcode.com/problems/sum-of-two-integers/
difficulty: Medium
topics:
  - "[[Bit Manipulation]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "a ^ b is the sum without carry, (a & b) << 1 is the carry. repeat until carry is 0"
time: "O(1)"
space: "O(1)"
date: 2026-08-23
---

# Problem
Add two ints without `+` or `-`.

# Approach
`a ^ b` = sum ignoring carries, `(a & b) << 1` = the carries. Repeat until no carry. Cast to `unsigned` before shifting, signed overflow on `<<` is UB before C++20.

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

### Complexity
- Time: $O(1)$, at most 32 steps
- Space: $O(1)$

## Recursive
Mistake I made: folding sum and carry into one do-while with a stale carry. `2 + 3` gave 1.

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

### Complexity
- Time: $O(1)$
- Space: $O(1)$

## Full Adder, Bit by Bit
Per bit: sum bit = `a ^ b ^ carry`, carry = majority of the three.

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

### Complexity
- Time: $O(1)$
- Space: $O(1)$
