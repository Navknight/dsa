---
link: https://leetcode.com/problems/house-robber-ii/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "circle: max of robbing 0..n-2 and 1..n-1"
time: "O(n)"
space: "O(1)"
date: 2026-08-22
---

# Problem
[[House Robber]] with houses in a circle, first and last are adjacent.

# Approach
Run linear House Robber on `0..n-2` and `1..n-1`, take the max.

## Tail Recursion
C++ doesn't guarantee tail calls, still O(n) stack.

### Code
```cpp
class Solution {
public:
    int steal(vector<int>& nums, int n, int i, int prev1, int prev2) {
        if (i == n)
            return prev1;

        return steal(nums, n, i + 1, max(prev1, nums[i] + prev2), prev1);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return nums[0];
        return max(steal(nums, n - 1, 0, 0, 0), steal(nums, n, 1, 0, 0));
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Two Variables

### Code
```cpp
class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i < end; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(robLinear(nums, 0, n - 1), robLinear(nums, 1, n));
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
