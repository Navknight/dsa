#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> diff(n + 2, 0);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }
    vector<int> freq(n + 1, 0);
    for (int i = 1; i <= n; i++)
        freq[i] = freq[i - 1] + diff[i];

    sort(freq.begin() + 1, freq.end());
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (ll)freq[i] * a[i - 1];

    cout << ans << endl;
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
