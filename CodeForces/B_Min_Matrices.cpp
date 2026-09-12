#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (k < n || k > 2 * n - 1)
        {
            cout << -1 << '\n';
            continue;
        }

        vector<vector<int>> a(n, vector<int>(n));

        int d = k - n;
        int normalCols = n - d;
        for (int i = 0; i < n; ++i)
        {
            a[i][i % normalCols] = i + 1;
        }

        for (int j = 0; j < d; ++j)
        {
            a[0][normalCols + j] = n + 1 + j;
        }

        int cur = n + d + 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] == 0)
                    a[i][j] = cur++;
            }
        }

        for (auto &row : a)
        {
            for (int x : row)
                cout << x << ' ';
            cout << '\n';
        }
    }
}