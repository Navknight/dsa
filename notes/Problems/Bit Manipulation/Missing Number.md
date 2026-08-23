---
difficulty: Easy
topics:
  - Bit Manipulation
  - Math
source: Leetcode
star: false
link: https://leetcode.com/problems/missing-number/
date: 2026-08-23
---

[[Bit Manipulation]] [[Math]]

# Problem
Given an array `nums` containing `n` distinct numbers from `0` to `n`, find the one number missing from the range.

# Approach
## XOR Cancellation
XOR every index `0..n` together with every value in `nums`. Any number that's actually present in `nums` appears exactly twice overall (once from the index range, once from `nums` itself) and cancels out (`x ^ x = 0`). The one number missing from `nums` only appears once (from the index range), so it's the only thing left un-canceled at the end.

`result` is initialized to `n` to account for the one index the loop itself never reaches (it only iterates `i = 0..n-1`, never `i = n`).

Preferred over a sum-based approach (`n(n+1)/2 - sum(nums)`) since XOR has no overflow risk for large `n`, where a sum could exceed `int` range.

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
