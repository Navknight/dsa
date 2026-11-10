#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int num1 = 0, mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            num1++;
            mini = min(i, mini);
            maxi = max(i, maxi);
        }
    }

    if (num1 == 2)
    {
        cout << 1 << endl;
    }
    else if (num1 == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << maxi - mini << endl;
    }
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
