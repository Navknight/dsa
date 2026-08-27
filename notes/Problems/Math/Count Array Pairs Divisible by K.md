---
difficulty: Medium
topics:
  - Math
  - Hash Maps
source: Leetcode
star: true
link: https://leetcode.com/problems/count-array-pairs-divisible-by-k/
date: 2026-08-21
---

[[Math]] [[Hash Maps]] [[GCD of Two Numbers]] [[Print all Divisors]]

# Problem
Given `nums` and `k`, count pairs `(i, j)` with `i < j` such that `nums[i] * nums[j] % k == 0`.

# Approach
## GCD Reduction + Divisor Bucket Map
Whether `k | a*b` only depends on `gcd(a,k)` and `gcd(b,k)`, not on the full value of `a` or `b`. For every prime `p | k` with exponent `e_p`, `v_p(gcd(a,k)) = min(v_p(a), e_p)` — so swapping `a` for `gcd(a,k)` never changes whether the divisibility condition holds. This means each `nums[i]` can be reduced to `g_i = gcd(nums[i], k)`, and `g_i` is always a divisor of `k` (so there are at most `d(k)` distinct values ever, regardless of `n`). See [[GCD of Two Numbers]].

Given `g_i`, the pair works iff `g_j` is a multiple of `factor = k / g_i` (since `g_i * factor = k`, and `k | g_i * g_j` reduces to `factor | g_j`).

So: keep a frequency map of `g` values seen so far. For each new `nums[i]`, compute `factor`, sum the frequencies of every key in the map that's a multiple of `factor`, then insert `g_i`. Querying *before* inserting is what keeps each pair counted exactly once — no self-pairing, no double counting from both directions.

First attempt was O(n²) (brute nested loop scanning `nums[j]` directly). Also tried building the full frequency map upfront then scanning it for every `i` — that double-counts every pair and includes self-matches, since the map already contains `nums[i]`'s own bucket when `i` is processed.

Prime-factorization-based bucketing (categorize by "does this share a prime factor with k") doesn't work — it drops exponent information. E.g. `k=8`, `nums=[2,2]`: both contain the prime factor 2, but `2*2=4` isn't divisible by 8.

Note: every key ever stored in the map is `gcd(nums[j], k)`, which is always a divisor of `k` — so the map self-limits to at most `d(k)` distinct keys without needing to precompute the divisor list separately (see [[Print all Divisors]]).

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
- Time: $O(n \cdot d(k))$ where $d(k)$ is the number of divisors of $k$ (at most ~128 for $k \le 10^5$), plus $O(\log(\min(a,b)))$ per gcd call
- Space: $O(d(k))$ for the frequency map
