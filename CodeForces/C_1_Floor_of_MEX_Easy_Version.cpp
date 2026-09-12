#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<long long> a(n + 1);

        for (int k = 1; k <= n; k++)
        {
            cin >> a[k];
        }

        vector<int> diff(n + 1, 0);

        for (int k = 1; k <= n; k++)
        {
            long long L = a[k] * k;
            long long R = (a[k] + 1) * k - 1;

            if (L >= n)
                continue;

            R = min(R, (long long)n - 1);

            diff[L]++;
            diff[R + 1]--;
        }

        vector<int> B;

        int forbidden = 0;

        for (int x = 0; x < n; x++)
        {
            forbidden += diff[x];

            if (forbidden == 0)
            {
                B.push_back(x);
            }
        }

        cout << B.size() << '\n';

        for (int x : B)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}