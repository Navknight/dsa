---
link: https://codeforces.com/problemset/problem/455/A
rating: 1300
contest: Codeforces Round 260
topics:
  - "[[Dynamic Programming]]"
source: CodeForces
star: false
blind75: false
mastery: yellow
review: 2026-09-27
insight: "House Robber over value buckets: taking value x scores a[x]*x but forbids x-1 and x+1, so dp[i] = max(dp[i+2] + a[i]*i, dp[i+1])"
time: "O(max_val)"
space: "O(max_val)"
date: 2026-09-24
code: "[[CodeForces/A_Boredom.cpp]]"
---

# Problem
Pick a value x, remove one occurrence of x and all occurrences of x-1 and x+1, gain x points each time. Maximize total points.

# Observation
Bucket count by value first (a[x] = how many times x appears). Once bucketed, this is [[House Robber]]: taking value i is worth a[i]*i but blocks i-1 and i+1, so dp[i] = max(dp[i+2] + a[i]*i, dp[i+1]). Same problem as [[Delete and Earn]], just with dense value buckets instead of a sparse map.

Mistakes I made:
- Seeded the two base cases (dp[lim], dp[lim-1]) with raw counts instead of a[i]*i, so the top of the array scored counts instead of points. Every other row had the multiply, just not the seeds.
- `#define lim 1e5` makes `lim` a double, so `a[i] * (lim-1)` silently becomes a double and breaks `max` against an `ll` — switched to `#define lim 100000`.
