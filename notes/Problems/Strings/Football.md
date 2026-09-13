---
difficulty: Easy
topics:
  - Strings
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/96/A
code: CodeForces/A_Football.cpp
date: 2026-09-13
---

[[CodeForces/A_Football.cpp]]
[[Strings]]

# Problem
Binary string of player positions. Dangerous if 7 or more same chars in a row.

# Approach
## Run Length Count
Track the current char and its run length. Reset to 1 when the char changes. Hit 7 means YES.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int curr = 0, count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' == curr)
            count++;
        else
        {
            count = 1;
            curr = s[i] - '0';
        }

        if (count == 7)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
