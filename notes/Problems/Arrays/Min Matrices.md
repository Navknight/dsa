---
difficulty: Medium
topics:
  - Arrays
  - Math
source: CodeForces
star: false
link: https://codeforces.com/contest/2263/problem/B
code: CodeForces/B_Min_Matrices.cpp
date: 2026-09-12
---

[[CodeForces/B_Min_Matrices.cpp]]
[[Arrays]] [[Math]]

# Problem
Build an `n x n` matrix using `1..n²` once each so the set of numbers that are the min of some row or column has size exactly `k`. Print -1 if impossible.

# Approach
## Constructive
Every row has a distinct min so `k >= n`. `1` is the min of both its row and column so `k <= 2n - 1`.

Let `d = k - n` extra minimums needed. Put `1..n` so every row gets its own min and they cover the first `n - d` columns (`a[i][i % (n-d)] = i+1`). Column mins there repeat row mins. The last `d` columns get `n+1..n+d` in row 0. Row 0 already has `1` so these only count as column mins. Fill the rest with bigger numbers.

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
        int n, k;
        cin >> n >> k;

        if (k < n || k > 2 * n - 1)
        {
            cout << -1 << '\n';
            continue;
        }

        vector<vector<int>> a(n, vector<int>(n));

        int d = k - n;
        int normalCols = n - d;
        for (int i = 0; i < n; ++i)
        {
            a[i][i % normalCols] = i + 1;
        }

        for (int j = 0; j < d; ++j)
        {
            a[0][normalCols + j] = n + 1 + j;
        }

        int cur = n + d + 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] == 0)
                    a[i][j] = cur++;
            }
        }

        for (auto &row : a)
        {
            for (int x : row)
                cout << x << ' ';
            cout << '\n';
        }
    }
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n^2)$
