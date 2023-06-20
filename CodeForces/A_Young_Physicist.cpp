#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x = 0, y = 0, z = 0;

    for (int i = 0; i < n; i++)
    {
        int xt;
        cin >> xt;
        x += xt;

        int yt;
        cin >> yt;
        y += yt;

        int zt;
        cin >> zt;
        z += zt;
    }
    cout << ((x != 0) ? "NO" : ((y != 0) ? "NO" : ((z != 0) ? "NO" : "YES")));

    return 0;
}