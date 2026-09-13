---
difficulty: Easy
topics:
  - Arrays
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/116/A
code: CodeForces/A_Tram.cpp
date: 2026-09-13
---

[[CodeForces/A_Tram.cpp]]
[[Arrays]]

# Problem
At each stop `a` people exit then `b` enter. Find the min tram capacity so it never overflows.

# Approach
## Simulation
Track current passengers (`curr - a + b`) and take the running max.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;

    int cap = INT_MIN;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        curr = curr - a + b;
        cap = max(cap, curr);
    }

    cout << cap << endl;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
