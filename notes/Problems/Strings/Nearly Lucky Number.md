---
difficulty: Easy
topics: ["Strings", "Math"]
source: CodeForces
star: false
link: "https://codeforces.com/problemset/problem/110/A"
code: ../../../CodeForces/A_Nearly_Lucky_Number.cpp
---

[[Strings]] [[Math]]

```cpp
# <bits/stdc++.h>

using namespace std;

bool isLucky(int x)
{
    if (x == 0)
        return false;
    while (x)
    {

        if (x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    string n;
    cin >> n;

    int l = 0;
    for (auto i : n)
        if (i == '4' || i == '7')
            l++;

    if (isLucky(l))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
```

