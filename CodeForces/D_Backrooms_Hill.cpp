#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> par(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        par[x] = i & 1;
    }
    int bal = 0;
    for (int v = n, k = 1; v >= 1; v--, k++)
    {
        bal += par[v] ? 1 : -1;
        if (k % 2 == 0 && bal != 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
