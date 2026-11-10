#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll moveDA(ll count)
{
    return count * 3;
}

ll moveAD(ll count)
{
    return count;
}

ll moveAA(ll count)
{
    return count * 2;
}

void solve()
{
    int n;
    cin >> n;

    ll d = 1, o = 0;
    while (n-- > 0)
    {
        ll no = moveDA(d) + moveAA(o);
        ll nd = moveAD(o);

        d = nd % mod;
        o = no % mod;
    }

    cout << (d % mod) << endl;
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
