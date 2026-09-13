---
difficulty: Easy
topics:
  - Greedy
  - Math
source: CodeForces
star: false
link: https://codeforces.com/contest/2263/problem/A
code: CodeForces/A_Min_Max_Game.cpp
date: 2026-09-12
---

[[CodeForces/A_Min_Max_Game.cpp]]
[[Greedy]] [[Math]]

# Problem
Binary array. Bessie goes first and merges two adjacent elements into their max. Elsie merges two adjacent into their min. Last element 1 means Bessie wins, 0 means Elsie wins. Who wins?

# Approach
## Count Ones vs Zeros
Each move can delete one of the opponent's values: Bessie merging a `0,1` pair kills a 0, Elsie kills a 1. So it's a race. Bessie moves first, so she wins when `count1 >= count0`.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int count1 = 0, count0 = 0;

        for (auto i : a)
        {
            if (i == 1)
                count1++;
            else
                count0++;
        }

        if (count1 >= count0)
            cout << "Bessie";
        else
            cout << "Elsie";
        cout << endl;
    }
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
