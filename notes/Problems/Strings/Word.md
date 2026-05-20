---
difficulty: Easy
topics: ["Strings"]
source: CodeForces
star: false
link: "https://codeforces.com/problemset/problem/59/A"
code: ../../../CodeForces/A_Word.cpp
---

[[Strings]]

```cpp
# <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int u = 0;
    int l = 0;
    string sl = "";
    string su = "";

    for (auto i : s)
    {
        if (i - 'a' < 0)
        {
            u++;
            su += i;
            sl += i - 'A' + 'a';
        }
        else
        {
            l++;
            sl += i;
            su += i - 'a' + 'A';
        }
    }

    if (l >= u)
        cout << sl;
    else
        cout << su;

    return 0;
}
```
