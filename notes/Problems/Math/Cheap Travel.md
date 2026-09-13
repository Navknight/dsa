---
difficulty: Medium
topics:
  - Math
  - Greedy
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/466/A
code: CodeForces/A_Cheap_Travel.cpp
date: 2026-09-13
---

[[CodeForces/A_Cheap_Travel.cpp]]
[[Math]] [[Greedy]]

# Problem
Need `n` rides. Single ticket costs `a`, an `m`-ride ticket costs `b`. Find min cost.

# Approach
## Compare Per-Ride Cost
If `m * a < b` the bulk ticket is never worth it, so pay `n * a`. Otherwise buy `n / m` bulk tickets and cover the leftover `n % m` rides with singles or one more bulk ticket, whichever is cheaper.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;

    cin >> n >> m >> a >> b;

    if (m * a < b)
    {
        cout << n * a << endl;
    }
    else
    {
        cout << (n / m) * b + min((n % m) * a, b) << endl;
    }
}
```

### Complexity
- Time: $O(1)$
- Space: $O(1)$
