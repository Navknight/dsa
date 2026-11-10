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
