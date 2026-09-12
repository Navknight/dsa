#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const int MAXN = 200000;

int main()
{
    vector<ll> fact(MAXN + 1, 1);

    for (int i = 1; i <= MAXN; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);

        for (ll &x : a)
            cin >> x;

        ll M = a.back();

        int k = n / 2;

        int q = (n - 1) / 2;

        ll smallest = a[1];

        vector<ll> candidates;

        candidates.push_back(smallest);

        if ((M - smallest) % q == 0)
        {
            ll D = (M - smallest) / q;

            if (D != smallest)
                candidates.push_back(D);
        }

        ll ans = 0;

        for (ll D : candidates)
        {
            if (D <= 0)
                continue;

            vector<ll> need;
            for (int i = 0; i < k; i++)
            {
                need.push_back(1LL * i * D);
            }

            for (int i = q; i >= 0; i--)
            {
                need.push_back(M - 1LL * i * D);
            }

            if ((int)need.size() != n)
                continue;

            sort(need.begin(), need.end());

            bool ok = true;

            for (int i = 0; i < n; i++)
            {
                if (need[i] != a[i])
                {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                continue;

            ll ways;

            if (n % 2 == 0)
            {
                ways = fact[k] * fact[k - 2] % MOD;
            }
            else
            {
                ways = fact[k] * fact[k - 1] % MOD;
            }

            ans += ways;
            ans %= MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}