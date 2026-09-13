---
difficulty: Medium
topics:
  - Prefix Sum
  - Sorting
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/433/B
code: CodeForces/B_Kuriyama_Mirai_s_Stones.cpp
date: 2026-09-13
---

[[CodeForces/B_Kuriyama_Mirai_s_Stones.cpp]]
[[Prefix Sum]] [[Sorting]]

# Problem
Array of stone costs. Type 1 query: sum of `a[l..r]`. Type 2 query: sum of `l`-th to `r`-th cheapest stones.

# Approach
## Two Prefix Sums
Build one prefix sum on the original array and one on a sorted copy. Each query is `pref[r] - pref[l-1]` on the right array. Sums go past int so use `long long`.

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> s = a;
    sort(s.begin(), s.end());

    vector<long long> prefA(n + 1, 0), prefS(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefA[i + 1] = prefA[i] + a[i];
        prefS[i + 1] = prefS[i] + s[i];
    }

    int m;
    cin >> m;

    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1)
            cout << prefA[r] - prefA[l - 1] << endl;
        else
            cout << prefS[r] - prefS[l - 1] << endl;
    }
}
```

### Complexity
- Time: $O(n \log n + m)$
- Space: $O(n)$
