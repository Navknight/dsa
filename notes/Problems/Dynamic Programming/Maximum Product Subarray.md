---
difficulty: Medium
topics:
  - Dynamic Programming
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/maximum-product-subarray/
date: 2026-08-22
---

[[Dynamic Programming]] [[Arrays]]

# Problem
Given an integer array `nums`, find a contiguous subarray with the largest product, and return that product.

# Approach
## Track Running Max and Min
Kadane's-style running sum doesn't work directly for products, because multiplying by a negative number *flips* the ordering — the most negative running product can become the largest positive product on the very next step. So at each index, track both the best (`maxp`) and worst (`minp`) product ending there, since either one might be the one that matters once a negative number shows up.

At each index `i`, three candidates for "best product ending exactly here": extend the previous max (`maxp * nums[i]`), extend the previous min (`minp * nums[i]` — this is the one that matters when `nums[i]` is negative), or start fresh (`nums[i]` alone, needed for cases like a `0` breaking the chain). `nmaxp` takes the max of the three, `nminp` takes the min.

Traced on `nums=[-2,3,-4]` (expected `24`): `maxp` goes `-2 → 3 → 24`, where the final `24` comes specifically from `minp[1] * nums[2] = -6 * -4 = 24` — the previous *worst* running product flipping into the new best the moment a negative number multiplies it.

Bugs hit along the way, worth remembering:
- Initializing `minp = nums[1]` instead of `nums[0]`. Both `maxp` and `minp` should start as "the product ending at index 0" — just `nums[0]` alone. Using `nums[1]` instead introduces a spurious candidate at `i=1`: `nums[1] * minp` becomes `nums[1] * nums[1]`, a square with no relation to any real subarray. Traced on `nums=[1,10]` (expected `10`): this produced `100` (`10*10`) as the max, a completely bogus value. Also a straight-up out-of-bounds crash risk if `nums.size() == 1`.
- `res` initialized to `-1e9` (or left unseeded) instead of `nums[0]`, and only updated starting from the loop at `i=1`. This misses the case where the best answer is just the first element alone. Traced on `nums=[2,-1]` (expected `2`): the loop's only candidate at `i=1` was `1`, so `res` ended at `1` instead of `2` — `nums[0]` was never considered as its own candidate anywhere.

Both fixed by seeding `maxp = minp = res = nums[0]` before the loop starts.

### Code
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0], minp = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int nmaxp = max({nums[i], nums[i] * maxp, nums[i] * minp});
            int nminp = min({nums[i], nums[i] * maxp, nums[i] * minp});
            res = max(res, nmaxp);
            maxp = nmaxp;
            minp = nminp;
        }

        return res;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
