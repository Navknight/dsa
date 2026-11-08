---
link: https://leetcode.com/problems/koko-eating-bananas/
difficulty: Medium
topics:
  - "[[Binary Search]]"
source: Leetcode
star: false
blind75: false
mastery: yellow
review: 2026-11-11
insight: "binary search the rate in [1, max pile], first rate where total hours <= h"
time: "O(n log max)"
space: "O(1)"
date: 2026-11-08
---

# Problem
Smallest eating rate that finishes all piles in `h` hours. A pile smaller than the rate still takes an hour.

# Approach
## Binary search on the answer
Hours only drop as the rate grows, so "finishes in time" is false then true. Find the first true.

- The answer is not always a pile size. `[3,6,7,11]` with `h = 8` is 4
- No sort needed
- `r = max(piles)` always works since `piles.size() <= h`, so use `l < r` with `r = m` and `l = m + 1`
- Total hours reaches about 10^12, use `long long`
- Ceiling: `(p + m - 1) / m`

### Mistakes
- Only tried rates equal to a pile size
- Mixed the two binary search forms, `l <= r` with `l = m` and `r = m`, infinite loop on `[1]`
- `int` for the hours total

### Code
```cpp
int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    while (l < r) {
        int m = l + (r - l) / 2;
        long long time = 0;
        for (int p : piles) time += (p + m - 1) / m;
        if (time > h) l = m + 1;
        else r = m;
    }
    return l;
}
```

### Complexity
- Time: $O(n \log \max)$
- Space: $O(1)$
