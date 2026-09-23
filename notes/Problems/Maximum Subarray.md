---
link: https://leetcode.com/problems/maximum-subarray/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Greedy]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
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
