---
link:
rating:
contest:
topics:
  - "[[Constructive]]"
  - "[[Math]]"
source: CodeForces
star: false
blind75: false
mastery:
review:
insight: "each detector end cuts one gap between neighbours, need n-1 cuts plus one end on an edge, so k = (n+1)/2. Place [i, i+k-1]"
time: "O(n)"
space: "O(1)"
date: 2026-10-17
code: "[[CodeForces/D_1_Come_Be_My_Friend_Don_t_Be_So_Scared_Easy_Version.cpp]]"
---

# Problem
Pick the fewest segments on 1..n so every spot gets a different yes/no pattern of "am I inside this segment".

# Observation
Neighbours i and i+1 differ only if some segment ends between them. There are n-1 gaps and each segment has 2 ends. Spots 1 and n can't both be uncovered or both read all "no", so one end sits on an edge. 2k >= n gives k = (n+1)/2.

Construction: k segments of length k shifted by one, [i, i+k-1]. For n=6 that's [1,3], [2,4], [3,5].

Mistakes I made:
- Misread it as covering all spots. A segment over everything says yes for all spots and tells nothing.
- Guessed k = n/3 + 1 from too few values. Fails at n=5.
- Forgot n = 1. The formula gives 1 and prints [1, 0]. Answer is 0.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int numDet = (n + 1) / 2;
    cout << numDet << endl;

    for (int i = 1; i < numDet; i++)
    {
        cout << i << " " << (i + numDet - 1) << endl;
    }
    cout << numDet << " " << n - 1 << endl;
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
