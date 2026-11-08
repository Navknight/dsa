---
link: https://leetcode.com/problems/missing-number/
difficulty: Easy
topics:
  - "[[Bit Manipulation]]"
  - "[[Math]]"
source: Leetcode
star: true
blind75: true
mastery: green
review: 2026-11-15
insight: "XOR all indices 0..n and all values, pairs cancel, missing one remains"
time: "O(n)"
space: "O(1)"
date: 2026-08-23
---

# Problem
Find the missing number in `0..n`.

# Approach
## XOR
Start with `n`, XOR every `i` and `nums[i]`. Present numbers cancel. No overflow, unlike the sum formula.

### Code
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            result ^= i ^ nums[i];
        }
        return result;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

- `n(n+1)/2` minus the array sum, `n = nums.size()`
- `n * (n + 1)` overflows int past n of about 46340. Accumulate `i - nums[i]` or XOR instead, both can't overflow
- Tests: `[3,0,1]` is 2, `[0]` is 1, `[1]` is 0
