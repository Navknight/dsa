---
difficulty: Medium
topics:
  - Prefix Sum
  - Greedy
  - Math
source: CodeForces
star: false
link: https://codeforces.com/contest/2263/problem/C1
code: CodeForces/C_1_Floor_of_MEX_Easy_Version.cpp
date: 2026-09-12
---

[[CodeForces/C_1_Floor_of_MEX_Easy_Version.cpp]]
[[Prefix Sum]] [[Greedy]] [[Math]]

# Problem
`f(B, k) = mex({floor(x / k) : x in B})`. Given `a_1..a_n`, build a set `B` of values in `[0, n-1]` with `f(B, k) = a_k` for every `k`.

# Approach
## Forbidden Ranges + Difference Array
For `mex` to be `a_k`, no `x` in `B` can have `floor(x / k) = a_k`. That bans the range `[a_k * k, (a_k + 1) * k - 1]`. Everything else is safe to add and only helps fill the smaller values the mex needs, so take every non-banned `x`.

Mark each banned range with a difference array (`diff[L]++`, `diff[R+1]--`), then sweep. `x` goes in `B` when its running count is 0.

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<long long> a(n + 1);

        for (int k = 1; k <= n; k++)
        {
            cin >> a[k];
        }

        vector<int> diff(n + 1, 0);

        for (int k = 1; k <= n; k++)
        {
            long long L = a[k] * k;
            long long R = (a[k] + 1) * k - 1;

            if (L >= n)
                continue;

            R = min(R, (long long)n - 1);

            diff[L]++;
            diff[R + 1]--;
        }

        vector<int> B;

        int forbidden = 0;

        for (int x = 0; x < n; x++)
        {
            forbidden += diff[x];

            if (forbidden == 0)
            {
                B.push_back(x);
            }
        }

        cout << B.size() << '\n';

        for (int x : B)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
