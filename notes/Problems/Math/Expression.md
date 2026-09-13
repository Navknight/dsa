---
difficulty: Easy
topics:
  - Math
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/479/A
code: CodeForces/A_Expression.cpp
date: 2026-09-13
---

[[CodeForces/A_Expression.cpp]]
[[Math]]

# Problem
Given `a`, `b`, `c` in order, place `+`, `*` and brackets to get the max value.

# Approach
## Try All Forms
Only 4 useful expressions: `a+b+c`, `(a+b)*c`, `a*(b+c)`, `a*b*c`. Take the max. (`a+b*c` and `a*b+c` are never better than one of these.)

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int ans = a + b + c;
    ans = max(ans, (a + b) * c);
    ans = max(ans, a * (b + c));
    ans = max(ans, a * b * c);
    cout << ans << endl;
}
```

### Complexity
- Time: $O(1)$
- Space: $O(1)$
