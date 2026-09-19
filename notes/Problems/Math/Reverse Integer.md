---
difficulty: Medium
topics:
  - Math
source: Leetcode
star: true
link: https://leetcode.com/problems/reverse-integer/
date: 2026-09-16
---

[[Math]]

# Problem
Reverse digits of a 32-bit signed integer. Return 0 if reversing overflows the 32-bit range.

# Approach
## Digit peeling with pre-multiply overflow check
Peel digits with `% 10` and `/ 10`. Check overflow before the multiply by comparing against `INT_MAX/10` and `INT_MIN/10`, handling the last digit edge case separately (7 for INT_MAX, -8 for INT_MIN since they end in 647/648).

### Code
```cpp
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) return 0;
            res = res * 10 + digit;
        }
        return res;
    }
};
```

### Complexity
- Time: $O(\log_{10} x)$
- Space: $O(1)$
