---
link: https://leetcode.com/problems/number-of-1-bits/
difficulty: Easy
topics:
  - "[[Bit Manipulation]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "add n & 1, shift right, 32 times"
time: "O(1)"
space: "O(1)"
date: 2026-08-23
---

# Problem
Count set bits in a 32-bit integer.

# Approach
## Check and Shift
Add `n & 1`, then `n >>= 1`.

Mistake I made: `n >>= n` instead of `n >>= 1`.

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
- Time: $O(1)$
- Space: $O(1)$
