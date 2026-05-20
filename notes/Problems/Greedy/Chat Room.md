---
difficulty: Easy
topics: ["Greedy", "Strings"]
source: CodeForces
star: false
link: "https://codeforces.com/problemset/problem/58/A"
code: CodeForces/A_Chat_room.cpp
---
[[CodeForces/A_Chat_room.cpp]]
[[Greedy]] [[Strings]]

```cpp
# <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<char> chars = {'h', 'e', 'l', 'l', 'o'};
    int j = 0;
    for (auto i : s)
    {
        if (j >= 5)
        {
            break;
        }
        else if (i == chars[j])
            j++;
    }
    if (j >= 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
```