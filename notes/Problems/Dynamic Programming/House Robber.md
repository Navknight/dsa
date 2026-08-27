---
difficulty: Medium
topics:
  - Dynamic Programming
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/house-robber/
code: LeetCode/House_robber.cpp
date: 2026-08-22
---

[[LeetCode/House_robber.cpp]]
[[Dynamic Programming]] [[Recursion]]

# Problem
Given an array of non-negative house values, find the max sum obtainable by robbing houses such that no two robbed houses are adjacent. Same shape as [[01 KnapSack]].

# Approach
1D DP: `rob(i) = max(nums[i] + rob(i+2), rob(i+1))` — the best you can do starting from house `i` is either rob it and skip to `i+2`, or skip it and move to `i+1`. Base case: past the end of the array, there's nothing left to rob, so `0`.

## Top-Down Memoization
Cache each index's result in an array to avoid recomputing overlapping subproblems.

Important pitfall: the "not yet computed" sentinel must be a value no real answer can take. Since house values are non-negative, every `rob(i)` is `>= 0` — so using `0` as the sentinel is wrong, it collides with legitimate zero-valued answers (e.g. an all-zero `nums`, or a suffix where skipping is optimal and the best is `0`). If the sentinel and a real answer overlap, the memo silently stops caching for every subproblem that evaluates to `0`, and the recursion degrades from $O(n)$ to the full exponential Fibonacci-shaped tree — traced concretely on `nums = [0,0,0,0,0,0,0,0,0,0]`, where *every* subproblem is `0`, so the memo never hits once. `-1` is the correct sentinel here, since it's outside the range of any real answer.

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
- Space: $O(n)$ for the memo array, plus $O(n)$ recursion stack

## Bottom-Up Tabulation
Same recurrence, filled iteratively instead of recursed.

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
- Space: $O(n)$ for the `dp` array

## Tail-Recursive Rolling Values
Same idea as tabulation, but carrying `prev2`/`prev1` as parameters instead of an array. First attempt used two redundant countdown indices (`h1`, `h2`) that always moved in lockstep, and computed `max(nums[i] + carried, nums[i])` at each step — since house values are non-negative, `nums[i] + carried >= nums[i]` always, so that `max` was dead code and every step unconditionally added, with two parallel chains double-accumulating. Traced on `nums=[2,1,1,2]` (correct answer `4`): the buggy version returned `6`. Fixed by collapsing to one index and one rolling pair, with the real recurrence's skip-branch (`prev1` carried untouched) actually reachable.

Still $O(n)$ stack space in C++ despite being tail-recursive — the standard doesn't guarantee tail-call elimination, so this isn't a genuine space optimization over tabulation, just a different style. See the same caveat in [[Climbing Stairs]].

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
- Space: $O(n)$ recursion stack, no array

## O(1) Space (Optimal)
Each state only ever depends on the previous two — same shape as [[Climbing Stairs]] — so the array collapses to two rolling variables in an iterative loop, no recursion needed (recursion can't reach true $O(1)$ here, per the caveat above).

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
