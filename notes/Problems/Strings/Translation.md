---
difficulty: Easy
topics:
  - Strings
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/41/A
code: CodeForces/A_Translation.cpp
date: 2026-09-13
---

[[CodeForces/A_Translation.cpp]]
[[Strings]]

# Problem
Check if string `t` is `s` reversed.

# Approach
## Reverse and Compare
Reverse `s` and compare. `s == t` works on `std::string` directly, no need for `strcmp`.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    if (strcmp((const char*)s.c_str(), (const char*)t.c_str()) == 0)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
