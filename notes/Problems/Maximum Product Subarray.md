---
link: https://leetcode.com/problems/maximum-product-subarray/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "track both max and min product ending here, a negative flips them"
time: "O(n)"
space: "O(1)"
date: 2026-08-22
---

# Problem
Max product of a contiguous subarray.

# Approach
## Running Max and Min
A negative flips the order, so keep both. New max/min from `nums[i]`, `nums[i] * maxp`, `nums[i] * minp`.

Mistakes I made: seeded `minp` with `nums[1]`, and `res` with `-1e9` so `nums[0]` alone was never a candidate. Seed all three with `nums[0]`.

### Code
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0], minp = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int nmaxp = max({nums[i], nums[i] * maxp, nums[i] * minp});
            int nminp = min({nums[i], nums[i] * maxp, nums[i] * minp});
            res = max(res, nmaxp);
            maxp = nmaxp;
            minp = nminp;
        }

        return res;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
