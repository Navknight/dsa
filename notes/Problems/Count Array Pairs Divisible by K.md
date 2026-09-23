---
link: https://leetcode.com/problems/count-array-pairs-divisible-by-k/
difficulty: Medium
topics:
  - "[[Math]]"
  - "[[Hash Maps]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "replace a with gcd(a,k), count earlier gcds that are multiples of k/g"
time: "O(n * d(k))"
space: "O(d(k))"
date: 2026-08-21
---

# Problem
Count pairs `i < j` with `nums[i] * nums[j] % k == 0`.

# Approach
## GCD Reduction + Bucket Map
`k | a*b` only depends on `gcd(a,k)` and `gcd(b,k)`. Reduce each value to `g = gcd(nums[i], k)`, always a divisor of `k`, so at most `d(k)` keys. See [[GCD of Two Numbers]].

Pair works iff the other `g` is a multiple of `k / g`. Query the map before inserting `g`, so each pair counts once.

Mistakes I made:
- Building the full map upfront double counts and self-pairs.
- Bucketing by shared prime factors drops exponents: `k=8, [2,2]`.

### Code
```cpp
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int g = gcd(k, nums[i]);
            int factor = k / g;
            for (auto iter : mp) {
                if (iter.first % factor == 0) {
                    ans += iter.second;
                }
            }
            mp[g]++;
        }
        return ans;
    }
};
```

### Complexity
- Time: $O(n \cdot d(k))$
- Space: $O(d(k))$
