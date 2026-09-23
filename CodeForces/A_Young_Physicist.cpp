#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        x += x1;
        y += y1;
        z += z1;
    }

    cout << ((x == 0 && y == 0 && z == 0) ? "YES" : "NO") << endl;
}
int main()
{
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
