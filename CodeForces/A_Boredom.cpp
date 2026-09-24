#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7

#define lim 100000
void solve()
{
    int n;
    cin >> n;

    vector<ll> a(lim + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    vector<ll> dp(lim + 1, 0);
    dp[lim] = a[lim] * lim;
    dp[lim - 1] = max(a[lim - 1] * (lim - 1), dp[lim]);

    for (int i = lim - 2; i >= 0; i--)
    {
        dp[i] = max(dp[i + 2] + a[i] * i, dp[i + 1]);
    }
    cout << dp[0] << endl;
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
