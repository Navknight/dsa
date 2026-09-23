---
link: https://leetcode.com/problems/n-th-tribonacci-number/
difficulty: Easy
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "T(n) = T(n-1) + T(n-2) + T(n-3), memo or keep the last three"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
`T(n) = T(n-1) + T(n-2) + T(n-3)`.

# Approach
## Memoization
Map cache, like [[Fibonacci Number]]. Three rolling variables make it O(1) space.

### Code
```cpp
unordered_map<int, int> a = {{0,0},{1,1}, {2,1}};

int trib(int n)
{
    if(a.find(n) != a.end())
        return a[n];
    else{
        a[n] = trib(n-1) + trib(n-2) + trib(n-3);
        return a[n];
    }
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
