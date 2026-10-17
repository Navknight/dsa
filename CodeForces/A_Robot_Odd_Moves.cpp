#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int a, b;
    cin >> a >> b;

    if ((a + b) % 2 == 0 && b <= a)
        cout << a << endl;
    else if ((a + b) % 2 == 1 && b <= a + 1)
        cout << a + 1 << endl;
    else
        cout << -1 << endl;
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
