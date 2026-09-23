---
link: https://leetcode.com/problems/maximum-subarray-sum-after-multiplier/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "3-state Kadane (before, inside, after the scaled segment), run once for * k and once for / k"
time: "O(n)"
space: "O(1)"
date: 2026-06-28
---

# Problem
Scale one subarray by `* k` or `/ k`, then max subarray sum.

# Approach
## 3-State Kadane
The sum subarray is unscaled prefix, scaled middle, unscaled suffix. States: `pre`, `mid`, `post`, each the best sum ending here. Run once for multiply, once for divide (C++ `/` truncates toward zero, which is what's asked). Save old `pre` and `mid` before updating.

### Code
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

### Complexity
- Time: $O(n)$
- Space: $O(1)$
