---
difficulty: Easy
topics:
  - Hash Maps
  - Arrays
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/469/A
code: CodeForces/A_I_Wanna_Be_the_Guy.cpp
date: 2026-09-13
---

[[CodeForces/A_I_Wanna_Be_the_Guy.cpp]]
[[Hash Maps]] [[Arrays]]

# Problem
Game has `n` levels. X can pass some levels and Y can pass some. Can they pass all `n` together?

# Approach
## Presence Array
Mark every level either one can pass in a bool array. If any level stays unmarked, print fail.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> a(n, false);

    int p;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        a[x-1] = true;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int y;
        cin >> y;
        a[y-1] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!a[i - 1])
        {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }
    cout << "I become the guy." << endl;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
