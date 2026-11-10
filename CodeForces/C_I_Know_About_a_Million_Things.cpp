#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;
    int odd = 0, even = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            even++;
        else
            odd++;
    }

    if (odd % 2 == 0)
        cout << "Moggity" << endl;
    else
    {
        if (odd == 3 && even == 0 || odd == 1 && even == 1)
            cout << "Larpity" << endl;
        else
            cout << "Moggity" << endl;
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
