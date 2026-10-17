#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;
    ll x, hi, lo, ans;
    cin >> x;
    hi = lo = ans = x;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        ans = max(ans, x + max(hi, -lo));
        ll newHi = x + max({0LL, hi, 2 * hi});
        ll newLo = x + min({0LL, lo, 2 * lo});
        hi = newHi;
        lo = newLo;
    }
    cout << ans << endl;
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
