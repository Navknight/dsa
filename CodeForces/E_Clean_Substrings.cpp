#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n, q;
    string s;
    cin >> n >> q >> s;
    ll c[2] = {0, 0}, B = 0;
    for (char ch : s) c[ch - '0']++;
    auto w = [&](ll j) { return (j >= 1 && j < n && s[j - 1] != s[j]) ? j * (n - j) : 0; }; // boundary between j and j+1 (1-indexed)
    for (ll j = 1; j < n; j++) B += w(j);
    cout << (B + c[0] * c[1]) / 2;
    while (q--)
    {
        ll i;
        cin >> i;
        B -= w(i - 1) + w(i);
        c[s[i - 1] - '0']--;
        s[i - 1] ^= 1;
        c[s[i - 1] - '0']++;
        B += w(i - 1) + w(i);
        cout << ' ' << (B + c[0] * c[1]) / 2;
    }
    cout << '\n';
}
int main() {
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
