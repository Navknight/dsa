---
link:
rating:
contest:
topics:
  - "[[Bit Manipulation]]"
  - "[[Greedy]]"
source: CodeForces
star: false
blind75: false
mastery:
review:
insight: "max never changes, any a[i] can reach any value in [a[i], max]. Answer is common prefix of min and max, then all 1s"
time: "O(n + log max)"
space: "O(1)"
date: 2026-10-17
code: "[[CodeForces/B_What_s_the_Capital_of_France.cpp]]"
---

# Problem
Operation on adjacent pair raises the lower one by 1. Maximize the OR of the array.

# Observation
The max M never changes and values only go up. The lower neighbour always rises, so the chain from M never breaks and every a[i] can reach any value in [a[i], M]. The min L has the widest range, so only L and M matter.

Above the first bit where L and M differ they share a prefix that can't change. At that bit M has 1 and L has 0, so x = prefix, 0, 111... sits in [L, M]. Answer is M | (2^k - 1) where k is the number of bits below the common prefix.

Mistakes I made:
- Thought the full mask 2^(bits of M) - 1 is always reachable. [5, 4] gives 5 because 2 and 3 are below 4.
- Thought the +1 chain to the max could break. It can't.
- Used `1 << k` instead of `(1 << k) - 1`. That's a single bit, not k ones, and breaks L == M too.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;

    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mini = min(x, mini);
        maxi = max(x, maxi);
    }

    int tempMax = maxi, tempMin = mini;
    int k = 0;
    while (tempMax != tempMin)
    {
        tempMax /= 2;
        tempMin /= 2;
        k++;
    }

    int toOr = (1 << k) - 1;

    cout << (maxi | toOr) << endl;
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
