#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.rbegin(), a.rend());

        vector<long long> pre(n + 1, 1), suf(n + 1, 1);
        for (int i = 1; i < n; i++)
            pre[i + 1] = pre[i] * i % MOD;
        for (int i = n - 1; i >= 1; i--)
            suf[i - 1] = suf[i] * i % MOD;

        long long ans = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                long long edges = (sum - i * (a[i] % MOD) % MOD + MOD) % MOD;
                ans = (ans + pre[i] * suf[i] % MOD * edges) % MOD;
            }
            sum = (sum + a[i]) % MOD;
        }
        cout << ans << endl;
    }
}
