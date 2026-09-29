#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &v : a)
        cin >> v;
    ll ans = 0;
    for (ll p = 2; p * p <= x || x > 1; p++)
    {
        if (p * p > x)
            p = x;
        if (x % p)
            continue;
        while (x % p == 0)
            x /= p;
        ll s = 0;
        for (ll v : a)
            if (v % p == 0)
                s += v;
        ans = max(ans, s);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
