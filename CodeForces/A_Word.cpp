#include <bits/stdc++.h>

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