---
difficulty: Easy
topics:
  - Greedy
  - Sorting
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/160/A
code: CodeForces/A_Twins.cpp
date: 2026-09-13
---

[[CodeForces/A_Twins.cpp]]
[[Greedy]] [[Sorting]]

# Problem
Take the min number of coins so your sum is strictly greater than the sum of the coins left.

# Approach
## Take Largest First
Sort and grab coins from the biggest end. Stop once taken sum beats the rest. Prefix sum gives the remaining sum directly (`pre[i]` is sum of coins before index `i`), though `total - sum` works too.

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
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }

    int count = 0, sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        count++;
        sum += a[i];

        if (sum > pre[i])
        {
            cout << count << endl;
            return 0;
        }
    }
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
