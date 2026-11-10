---
link: https://leetcode.com/problems/single-number/
difficulty: Easy
topics:
  - "[[Bit Manipulation]]"
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery: green
review: 2026-11-18
insight: "XOR everything, pairs cancel (a ^ a = 0, a ^ 0 = a)"
time: "O(n)"
space: "O(1)"
date: 2026-11-11
---

# Problem
Every value appears twice except one. Find it in O(1) space.

# Approach
## XOR
Pairs cancel, XOR is order independent, so only the single value is left.

### Code
```cpp
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) ans ^= x;
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
