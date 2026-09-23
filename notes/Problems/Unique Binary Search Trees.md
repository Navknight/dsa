---
link: https://leetcode.com/problems/unique-binary-search-trees/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "catalan: dp[n] = sum dp[i-1] * dp[n-i]"
time: "O(n²)"
space: "O(n)"
date: 
---

# Problem
Number of unique BSTs with `n` nodes.

# Approach
## Catalan
Root `i` leaves `i - 1` nodes on the left and `n - i` on the right: `t[n] = sum t[i-1] * t[n-i]`. See [[Catalan's Number]].

### Code
```cpp
int numTrees(int n) {
    vector<int>t (n+1, 1);

    for(int i = 2; i < n+1; i++){
        int total = 0;
        for(int j = 1; j <= i; j++){
            total += t[j-1]*t[i-j];
        }
        t[i] = total;
    }

    return t[n];
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$
