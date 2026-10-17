#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a != pos)
        {   
            pos = (a - pos) + a;
        }
    }
    cout <<((n%2 == 0)?-1*( pos / 2 ) : pos/2)<< endl;
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
