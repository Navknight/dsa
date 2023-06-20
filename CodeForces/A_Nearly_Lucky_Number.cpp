#include <bits/stdc++.h>

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