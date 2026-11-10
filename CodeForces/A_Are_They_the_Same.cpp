#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n, k;
    cin >> n >> k;
    int oa = 0, ob = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        oa += x & 1;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ob += x & 1;
    }
    bool ok = (k & 1) ? (n - ob <= n - oa) : (ob <= oa);
    cout << (ok ? "YES" : "NO") << "\n";
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
