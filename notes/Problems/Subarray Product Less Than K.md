---
link: https://leetcode.com/problems/subarray-product-less-than-k/
difficulty: Medium
topics:
  - "[[Sliding Window]]"
  - "[[Two Pointers]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sliding window, shrink while product >= k, add r - l + 1 subarrays ending at r"
time: "O(n)"
space: "O(1)"
date: 2023-04-09
---

# Problem
Count subarrays with product < `k`.

# Approach
## Sliding Window
Grow right, shrink left while product >= `k`. Each `r` adds `r - l + 1` subarrays ending at `r`. `k <= 1` means 0.

### Code
```cpp
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int mul = 1;
    int ans = 0;
    if (k <= 1)
        return ans;
    int left = 0, right = 0;
    while (right < nums.size())
    {
        mul *= nums[right];

        while (mul >= k)
        {
            mul /= nums[left];
            left++;
        }

        ans += right - left + 1;
        right++;
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
