---
link: https://leetcode.com/problems/reverse-integer/
difficulty: Medium
topics:
  - "[[Math]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "check overflow against INT_MAX/10 before multiplying"
time: "O(log x)"
space: "O(1)"
date: 2026-09-16
---

# Problem
Reverse the digits of a 32-bit int, 0 on overflow.

# Approach
## Digit Peeling
`% 10` and `/ 10`. Before multiplying check against `INT_MAX / 10` and `INT_MIN / 10`, last digit limits 7 and -8.

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
- Time: $O(\log x)$
- Space: $O(1)$
