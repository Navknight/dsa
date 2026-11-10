---
link: https://leetcode.com/problems/number-of-1-bits/
difficulty: Easy
topics:
  - "[[Bit Manipulation]]"
source: Leetcode
star: true
blind75: true
mastery: yellow
review: 2026-11-13
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

### Mistakes
- `n >>= n` instead of `n >>= 1`
- Shifted `ans` (`ans = ans >> 1`) instead of `n`. `n` never changed and the count was wiped each pass, returned 0 for every input

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

## Brian Kernighan
`n &= n - 1` clears the lowest set bit, so the loop runs once per set bit. Subtracting 1 flips the lowest set bit to 0 and everything below it to 1, the AND clears just that bit. Same trick as Power of Two and Counting Bits.

### Code
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= n - 1;
            ans++;
        }
        return ans;
    }
};
```

### Complexity
- Time: $O(k)$, k = number of set bits
- Space: $O(1)$
