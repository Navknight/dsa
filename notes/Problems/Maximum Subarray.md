---
link: https://leetcode.com/problems/maximum-subarray/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Greedy]]"
source: Leetcode
star: true
blind75: true
mastery: green
review: 2026-11-15
insight: "Kadane: curr = max(nums[i], curr + nums[i]), answer is the max over all i"
time: "O(n)"
space: "O(1)"
date: 2026-08-22
---

# Problem
Max sum of a contiguous subarray.

# Approach
## Kadane's
`dp[i] = max(nums[i], nums[i] + dp[i-1])`. Greedy view: drop a negative running sum. Answer is the max over every `i`, not the last one.

- It is 1D, `dp[i]` reads only `dp[i-1]`, so one variable is enough
- Need the subarray itself: set `start = i` when starting fresh, save `bestStart`/`bestEnd` when `ans` improves

### Mistakes
- Described the choice at `i` as include or skip. It is extend or start fresh, skipping breaks contiguity
- Start `ans` at `nums[0]`, not 0, or `[-3, -1, -2]` gives 0

### Code
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev1 = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = max(nums[i], nums[i] + prev1);
            ans = max(ans, curr);
            prev1 = curr;
        }

        return ans;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
