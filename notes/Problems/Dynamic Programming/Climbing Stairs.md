---
difficulty: Easy
topics:
  - Dynamic Programming
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/climbing-stairs/
code: LeetCode/Climbing Stairs.cpp
date: 2026-08-22
---

[[LeetCode/Climbing Stairs.cpp]]
[[Dynamic Programming]] [[Recursion]]

# Problem
Given `n` steps, where each move climbs either 1 or 2 steps, count the number of distinct ways to reach the top.

# Approach
Classic 1D DP — `ways(i) = ways(i-1) + ways(i-2)` (same recurrence shape as Fibonacci), since the last move to reach step `i` was either a 1-step from `i-1` or a 2-step from `i-2`. Base cases: `ways(1) = 1`, `ways(2) = 2`.

## Bottom-Up Tabulation
Build the full array up from the base cases.

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
- Space: $O(n)$ for the `ways` array

## Top-Down Memoization
Same recurrence, computed recursively with an array as the cache (`0` works as the "not yet computed" sentinel since every real answer is positive). Same $O(n)$/$O(n)$ complexity as tabulation, just with recursion call overhead and $O(n)$ stack depth added on top — a style choice, not an optimization. Compared to the hashmap-based memoization in `LeetCode/Climbing Stairs.cpp`, an array cache avoids hashing overhead when the input range (`0..n`) is known upfront.

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
- Space: $O(n)$ for the cache, plus $O(n)$ recursion stack

## O(1) Space (Optimal)
At any step, only the previous two values are ever needed — so the whole array collapses into two rolling variables.

Recursion can't get you to $O(1)$ space here even in principle: every call pushes a stack frame in C++, and while a tail-recursive rewrite (passing the running values as parameters, recursive call as the last operation) is possible, the C++ standard doesn't guarantee tail-call elimination the way some functional languages do. Whether that collapses to a loop is compiler/optimization-level dependent, not something to rely on for complexity claims — so true $O(1)$ space requires the iterative version below.

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
