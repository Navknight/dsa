---
difficulty: Medium
topics:
  - Greedy
  - Arrays
  - Sorting
source: Leetcode
star: false
link: https://leetcode.com/contest/weekly-contest-508/problems/maximum-total-sum-of-k-selected-elements/
date: 2026-06-28
---

[[Greedy]] [[Arrays]] [[Sorting]]

# Problem
Given `nums`, select `k` elements and process one by one. For each, either add its value or multiply by current `mul` (then `mul` decreases by 1). Return max possible total sum. Constraint: `nums[i] >= 1`.

# Approach
## Greedy: Sort and Take k Largest

Sort, take `k` largest elements. For each, multiply if `mul > 1` (guaranteed better for positive nums), else add. Apply highest multiplier to largest element first by iterating from end.

Cast to `long long` before multiply: `int * int` overflows for large `nums[i]` and `mul`.

# Code
```cpp
long long maxSum(vector<int>& nums, int k, int mul) {
    sort(nums.begin(), nums.end());
    int n = nums.size() - 1;
    long long sum = 0;
    while (k--) {
        sum += mul > 1 ? (long long)nums[n] * mul : nums[n];
        n--;
        mul--;
    }
    return sum;
}
```

# Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
