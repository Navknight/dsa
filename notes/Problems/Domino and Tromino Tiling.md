---
link: https://leetcode.com/problems/domino-and-tromino-tiling/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "dp[n] = 2*dp[n-1] + dp[n-3]"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Ways to tile a `2 x n` board with dominoes and trominoes, mod 1e9+7.

# Approach
## Pattern
`t[n] = 2 * t[n-1] + t[n-3]`, base 1, 2, 5.

### Code
```cpp
int numTilings(int n) {
    vector<long long> t(1001, 0);
    int mod = 1e9 + 7;
    t[0] = 0;
    t[1] = 1;
    t[2] = 2;
    t[3] = 5;
    for(int i = 4; i < n+1; i++){
        t[i] = 2*t[i-1] + t[i-3];
        t[i] %= mod;
    }

    return t[n];
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
