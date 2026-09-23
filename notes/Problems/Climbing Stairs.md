---
link: https://leetcode.com/problems/climbing-stairs/
difficulty: Easy
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "ways(i) = ways(i-1) + ways(i-2), keep only the last two"
time: "O(n)"
space: "O(1)"
date: 2026-08-22
---

# Problem
Climb 1 or 2 steps at a time. Count ways to reach step `n`.

# Approach
`ways(i) = ways(i-1) + ways(i-2)`, Fibonacci. Base: `ways(1) = 1`, `ways(2) = 2`.

## Tabulation

### Code
```cpp
class Solution {
public:
    vector<int> ways;

    int climbStairs(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        ways = vector<int>(n + 1);
        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 2;

        for (int i = 3; i <= n; i++) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }

        return ways[n];
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Memoization
Array cache, 0 = not computed.

### Code
```cpp
class Solution {
public:
    vector<int> ways;

    int find(int n) {
        if (n < 3)
            return n;

        if (ways[n] > 0)
            return ways[n];

        return ways[n] = find(n - 1) + find(n - 2);
    }

    int climbStairs(int n) {
        if (n < 3)
            return n;
        ways = vector<int>(n + 1);
        ways[1] = 1;
        ways[2] = 2;
        return find(n);
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$ + $O(n)$ stack

## Two Variables
Only the last two values are needed. Recursion can't get to O(1) space, C++ doesn't guarantee tail calls.

### Code
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
            return n;

        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
