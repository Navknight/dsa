#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
const int V = 3000;

short g[V + 1][V + 1];

int main()
{
    vector<vector<int>> pf(V + 1);
    for (int p = 2; p <= V; p++)
        if (pf[p].empty())
            for (int m = p; m <= V; m += p)
                pf[m].push_back(p);

    for (int v = 1; v <= V; v++)
    {
        g[v][v] = v;
        for (int u = 1; u < v; u++)
        {
            int best = 0;
            bool onlyV = false, onlyU = false, both = false;
            for (int p : pf[v])
                (u % p ? onlyV : both) = true;
            for (int p : pf[u])
                if (v % p)
                    onlyU = true;
            if (onlyV)
                best = max(best, (int)g[u][v - 1]);
            if (onlyU)
                best = max(best, (int)g[u - 1][v]);
            if (both)
                best = max(best, (int)g[u - 1][v - 1]);
            g[u][v] = best;
        }
    }

    vector<long long> pw(V + 1, 1);
    for (int i = 1; i <= V; i++)
        pw[i] = pw[i - 1] * 2 % MOD;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> cnt(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }

        vector<int> pre(n + 1, 0);
        for (int v = 1; v <= n; v++)
            pre[v] = pre[v - 1] + cnt[v];

        long long ans = 0;
        for (int lo = 1; lo <= n; lo++)
        {
            if (!cnt[lo])
                continue;
            long long wl = pw[cnt[lo]] - 1;
            ans = (ans + wl * lo) % MOD;
            for (int hi = lo + 1; hi <= n; hi++)
            {
                if (!cnt[hi])
                    continue;
                long long ways = wl * (pw[cnt[hi]] - 1) % MOD * pw[pre[hi - 1] - pre[lo]] % MOD;
                ans = (ans + ways * g[lo][hi]) % MOD;
            }
        }

        cout << ans << endl;
    }
}
