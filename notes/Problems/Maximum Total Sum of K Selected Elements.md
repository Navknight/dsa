---
link: https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
difficulty: Medium
topics:
  - "[[Greedy]]"
  - "[[Sorting]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sort, give the biggest multiplier to the biggest element, multiply while mul > 1"
time: "O(n log n)"
space: "O(1)"
date: 2026-06-28
---

# Problem
Pick `k` elements. Each one either adds its value or its value * `mul`, then `mul` drops by 1. Max total.

# Approach
## Greedy
Sort, take the `k` largest from the back. Multiply while `mul > 1`, else add. Cast to `long long` before multiplying.

### Code
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

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
