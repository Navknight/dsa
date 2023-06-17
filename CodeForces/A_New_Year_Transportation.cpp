#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> g(n, {0, 0});
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        g[i] = {i, x + i};
    }

    int i = 1;
    while (i != n)
    {
        if (i == t)
        {
            cout << "YES" << endl;
            return 0;
        }

        else
        {
            i = g[i].second;
        }
    }
    if (i == t)
    {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}