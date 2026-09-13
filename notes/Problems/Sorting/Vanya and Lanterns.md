---
difficulty: Medium
topics:
  - Sorting
  - Greedy
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/492/B
code: CodeForces/B_Vanya_and_Lanterns.cpp
date: 2026-09-12
---

[[CodeForces/B_Vanya_and_Lanterns.cpp]]
[[Sorting]] [[Greedy]]

# Problem
Street of length `l` with `n` lanterns at given positions. Find the min radius `d` so the whole street is lit.

# Approach
## Max Gap
Sort positions. Between two lanterns you need half the gap. At the ends there is only one lantern, so you need the full distance to `0` and to `l`. Answer is the max of these.

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    double dist = 0.0;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        double d = a[i] - last;
        if (i == 0)
            dist = max(dist, d);
        else
            dist = max(dist, d / 2);
        last = a[i];
    }
    dist = max(dist, (double)(l - last));

    cout << fixed << setprecision(10) << dist << endl;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
