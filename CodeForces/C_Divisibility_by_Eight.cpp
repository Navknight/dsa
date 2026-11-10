#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        int a = s[i] - '0';
        if (a % 8 == 0)
        {
            cout << "YES" << endl << a << endl;
            return;
        }
        if (a == 0)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            int b = a * 10 + (s[j] - '0');
            if (b % 8 == 0)
            {
                cout << "YES" << endl << b << endl;
                return;
            }
            for (int k = j + 1; k < n; k++)
            {
                int c = b * 10 + (s[k] - '0');
                if (c % 8 == 0)
                {
                    cout << "YES" << endl << c << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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
