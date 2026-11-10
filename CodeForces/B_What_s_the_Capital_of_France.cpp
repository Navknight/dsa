#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    int n;
    cin >> n;

    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mini = min(x, mini);
        maxi = max(x, maxi);
    }

    int tempMax = maxi, tempMin = mini;
    int k = 0;
    while (tempMax != tempMin)
    {
        tempMax /= 2;
        tempMin /= 2;
        k++;
    }

    int toOr = (1 << k) - 1;

    cout << (maxi | toOr) << endl;
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
