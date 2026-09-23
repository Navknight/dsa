---
link: https://leetcode.com/problems/house-robber/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "rob(i) = max(nums[i] + rob(i+2), rob(i+1)), keep two variables"
time: "O(n)"
space: "O(1)"
date: 2026-08-22
---

# Problem
Max sum of non-adjacent houses.

# Approach
`rob(i) = max(nums[i] + rob(i+2), rob(i+1))`, past the end = 0.

## Memoization
Trap: sentinel 0 collides with real answers of 0, memo never hits. Use -1.

### Code
```cpp
int helper(vector<int> &nums, int index, vector<int> &memo)
{
    if (index >= nums.size())
        return 0;

    if (memo[index] != -1)
        return memo[index];

    int robCurrent = nums[index] + helper(nums, index + 2, memo);
    int skipCurrent = helper(nums, index + 1, memo);

    return memo[index] = max(robCurrent, skipCurrent);
}

int rob(vector<int> &nums)
{
    vector<int> memo(nums.size(), -1);
    return helper(nums, 0, memo);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Tabulation

### Code
```cpp
int robber(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);

    return dp[n - 1];
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Tail Recursion
Mistake I made: two lockstep indices and a dead `max`, `[2,1,1,2]` gave 6. Still O(n) stack.

### Code
```cpp
class Solution {
public:
    int steal(vector<int>& nums, int i, int prev2, int prev1) {
        if (i == nums.size())
            return prev1;

        return steal(nums, i + 1, prev1, max(prev2 + nums[i], prev1));
    }

    int rob(vector<int>& nums) { return steal(nums, 0, 0, 0); }
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
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int num : nums) {
            int curr = max(prev2 + num, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
