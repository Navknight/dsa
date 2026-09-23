---
link: https://leetcode.com/problems/fibonacci-number/
difficulty: Easy
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "same as climbing stairs, keep the last two values"
time: "O(n)"
space: "O(1)"
date: 2023-05-19
---

# Problem
Return the `n`th Fibonacci number.

# Approach
## Memoization
Map as the cache. Same recurrence as [[Climbing Stairs]], two variables would make it O(1) space.

### Code
```cpp
unordered_map<int, int> a = {{0,0},{1,1}, {2,1}};

int fib(int n)
{
    if(a.find(n) != a.end())
        return a[n];
    else{
        a[n] = fib(n-1) + fib(n-2);
        return a[n];
    }
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
