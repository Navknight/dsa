---
link:
rating:
contest:
topics:
  - "[[Greedy]]"
  - "[[Implementation]]"
source: CodeForces
star: false
blind75: false
mastery:
review:
insight: "count k of 1s is fixed. k=1 gives 0, k=2 gives 1, k>=3 gives last 1 minus first 1"
time: "O(n)"
space: "O(1)"
date: 2026-10-17
code: "[[CodeForces/A_Hey_It_s_Me_Souvlakity.cpp]]"
---

# Problem
Numbers 1..n split by a binary string. Players alternate handing one of their own numbers to the other, game ends on Kalamakity's turn. Souvlakity maximizes the range of his set and Kalamakity minimizes it.

# Observation
Each pair of turns gives one and takes one, so Souvlakity ends with exactly k = count of 1s.
- k=1: one number left, answer 0.
- k=2: he keeps one number b, Kalamakity hands back b±1, answer 1.
- k>=3: he gives away a middle number so min and max stay. Kalamakity hands back whatever he got so the set never grows. Answer is last 1 minus first 1.

Mistakes I made:
- Updated `mini`/`maxi` outside the `if (s[i] == '1')`, so it tracked every index and printed n-1 for every k>=3.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int num1 = 0, mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            num1++;
            mini = min(i, mini);
            maxi = max(i, maxi);
        }
    }

    if (num1 == 2)
    {
        cout << 1 << endl;
    }
    else if (num1 == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << maxi - mini << endl;
    }
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```
