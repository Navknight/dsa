#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin >> n;

    vector<ll> a(100001, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    vector<ll> dp(100001, 0);
    dp[1] = a[1];
    dp[2] = max(a[2] * 2, a[1]);
    for (int i = 3; i < 100001; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);

    cout << dp[100000] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
