---
link:
rating:
contest:
topics:
  - "[[Math]]"
  - "[[Constructive]]"
source: CodeForces
star: false
blind75: false
mastery:
review:
insight: "only odd count matters. Even odds wins by taking all. Odd odds wins unless start is (1 odd, 1 even) or (3 odd, 0 even)"
time: "O(n)"
space: "O(1)"
date: 2026-10-17
code: "[[CodeForces/C_I_Know_About_a_Million_Things.cpp]]"
---

# Problem
Players alternate removing a non-empty set of elements. Allowed if it's a single element or the sum is even. Player facing empty array loses.

# Observation
Sum is even iff the count of odds in it is even. Evens are free.
- O even: take everything, win.
- O odd: never leave the opponent an even O. Losing states are empty, (1,1) and (3,0). From any other odd O start you can remove an even number of odds plus evens to land on (1,1) or (3,0).

Larpity wins only on (1,1) and (3,0). Checked with a brute force over (O, E) up to 11.

Mistakes I made:
- Thought an even sum needs equal evens and odds. Only the odd count matters.
- Thought leaving any odd O wins. (1,0) loses for the one who leaves it.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;
    int odd = 0, even = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            even++;
        else
            odd++;
    }

    if (odd % 2 == 0)
        cout << "Moggity" << endl;
    else
    {
        if (odd == 3 && even == 0 || odd == 1 && even == 1)
            cout << "Larpity" << endl;
        else
            cout << "Moggity" << endl;
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
