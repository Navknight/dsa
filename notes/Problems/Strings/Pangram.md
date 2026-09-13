---
difficulty: Easy
topics:
  - Strings
  - Hash Maps
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/520/A
code: CodeForces/A_Pangram.cpp
date: 2026-09-13
---

[[CodeForces/A_Pangram.cpp]]
[[Strings]] [[Hash Maps]]

# Problem
Check if a string contains every letter of the alphabet, ignoring case.

# Approach
## 26-Slot Presence Array
Map each char to `c - 'A'` or `c - 'a'` and mark it. Any unmarked slot means NO.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> present(26, false);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        if (c >= 'A' && c <= 'Z')
            present[c - 'A'] = true;
        else
            present[c - 'a'] = true;
    }

    for (auto i : present)
    {
        if (!i)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
