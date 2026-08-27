---
difficulty: Medium
topics:
  - Dynamic Programming
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/house-robber-ii/
date: 2026-08-22
---

[[Dynamic Programming]] [[Recursion]] [[House Robber]]

# Problem
Same as [[House Robber]], but houses are arranged in a circle — house `0` and house `n-1` are adjacent, so they can't both be robbed.

# Approach
The only extra constraint over the linear version is "can't take both house `0` and house `n-1`." So run the ordinary linear House Robber recurrence twice — once over houses `0..n-2` (excluding the last), once over `1..n-1` (excluding the first) — and take the max. Every valid circular selection satisfies at least one of those two exclusions, so this covers the whole search space correctly.

## Tail-Recursive Rolling Values
Reuses the [[House Robber]] tail-recursive shape (`prev1`/`prev2` carried as parameters), called twice with different index ranges to implement the exclude-first / exclude-last split.

Verified on both LeetCode examples: `nums=[2,3,2]` gives `max(3,3)=3`; `nums=[1,2,3,1]` gives `max(4,3)=4` (the `4` comes from robbing houses `0` and `2` in the excluded-last range).

Still $O(n)$ recursion stack in C++, same caveat as [[House Robber]] — tail form doesn't guarantee $O(1)$ space without a compiler doing the elimination itself.

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
- Space: $O(n)$ recursion stack

## O(1) Space (Optimal)
Same idea, but iterative — two rolling variables per range instead of recursion, so no stack growth at all.

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
