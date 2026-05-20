---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=study-plan-v2&envId=dynamic-programming"
---

[[Dynamic Programming]]

# Problem
You have two types of tiles: a `2 x 1` domino shape and a tromino shape. You may rotate these shapes.

![](https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg)

Given an integer n, return _the number of ways to tile an_ `2 x n` _board_. Since the answer may be very large, return it **modulo** `109 + 7`.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

# Solution
This problem is more about pattern recognisation than dynamic programming, here the number of ways has a clear pattern to it and does not require much coding to write the answer

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

