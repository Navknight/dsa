---
difficulty: Medium
topics:
  - Greedy
  - Math
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/520/B
code: CodeForces/B_Two_Buttons.cpp
date: 2026-09-13
---

[[CodeForces/B_Two_Buttons.cpp]]
[[Greedy]] [[Math]]

# Problem
Start at `n`. Red button doubles, blue button subtracts 1. Find min presses to reach `m`.

# Approach
## Work Backwards from m
Reverse the ops: halve `m` (if even) or add 1. If `m` is odd you must add 1 first. Keep halving while `m > n`, then close the gap with `n - m` subtractions. If `m <= n` the answer is just `n - m`.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if (m <= n)
    {
        cout << n - m << endl;
        return 0;
    }
    else
    {
        int ops = 0;
        while (m > n)
        {
            if (m % 2 != 0)
            {
                ops++;
                m++;
            }
            m /= 2;
            ops++;
        }
        cout << ops + n - m << endl;
    }
}
```

### Complexity
- Time: $O(\log m)$
- Space: $O(1)$
