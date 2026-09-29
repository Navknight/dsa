#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    int ans = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (s[i] != s[j])
            ans += (s[i] == c || s[j] == c) ? 1 : 2;
    cout << ans << '\n';
}
int main() {
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
