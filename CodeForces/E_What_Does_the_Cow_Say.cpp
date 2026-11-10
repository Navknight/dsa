#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> open, close;
    int i = 0;
    while (i < n)
    {
        ll o = 0, c = 0;
        while (i < n && s[i] == '(')
        {
            o++;
            i++;
        }
        while (i < n && s[i] == ')')
        {
            c++;
            i++;
        }
        open.push_back(o);
        close.push_back(c);
    }
    int sz = open.size();

    vector<ll> before(sz), after(sz), closed(sz);
    ll cur = 0, cl = 0;
    for (int j = 0; j < sz; j++)
    {
        before[j] = cur;
        closed[j] = cl;
        cur += open[j];
        after[j] = cur;
        cur -= close[j];
        cl += close[j];
    }

    ll ans = 0;
    for (int j = 0; j < sz; j++)
    {
        if (closed[j] > k)
            break;
        ans = max(ans, min(n / 2, after[j] + k));
    }

    multiset<ll> st;
    int l = 0;
    for (int j = 0; j < sz; j++)
    {
        st.insert(before[j]);
        while (closed[j] - closed[l] > k)
        {
            st.erase(st.find(before[l]));
            l++;
        }
        ans = max(ans, after[j] - *st.begin());
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
