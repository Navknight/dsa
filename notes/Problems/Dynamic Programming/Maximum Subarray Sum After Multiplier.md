---
difficulty: Hard
topics:
  - Dynamic Programming
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/contest/weekly-contest-508/problems/maximum-subarray-sum-after-multiplier/
date: 2026-06-28
---

[[Dynamic Programming]] [[Arrays]]

# Problem
Given `nums` and `k`, choose one subarray and either multiply every element by `k` or divide (floor for positive, ceil for negative). Return max possible subarray sum in the resulting array. The operation subarray and sum subarray can differ.

# Approach
## 3-State Kadane's (Two Runs)

The operation subarray is only useful if it overlaps the sum subarray. So the sum subarray has three regions: unscaled prefix, scaled middle, unscaled suffix.

Run 3-state Kadane's twice: once for multiply (`sv = v*k`), once for divide (`sv = v/k`, C++ truncation gives floor for positive and ceil for negative automatically).

Three states at each position, tracking max sum of subarray ending here:
- `pre`: no scaling yet (standard Kadane's)
- `mid`: current element is scaled (enter from `pre`, extend `mid`, or start fresh scaled)
- `post`: exited scaling zone, back to normal (enter from `mid` or extend `post`)

Use old values for transitions: save `pre` and `mid` before updating.

# Code
```cpp
long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    long long ans = LLONG_MIN;
    for (int t = 0; t < 2; t++) {
        long long pre  = nums[0];
        long long mid  = (t == 0) ? (long long)nums[0] * k : nums[0] / k;
        long long post = LLONG_MIN / 2;
        ans = max({ans, pre, mid});
        for (int i = 1; i < n; i++) {
            long long v = nums[i];
            long long sv = (t == 0) ? v * k : v / k;
            long long oldPre = pre, oldMid = mid;
            pre  = max(pre + v, v);
            mid  = max({oldMid + sv, oldPre + sv, sv});
            post = max(post + v, oldMid + v);
            ans  = max({ans, pre, mid, post});
        }
    }
    return ans;
}
```

# Complexity
- Time: $O(n)$
- Space: $O(1)$
