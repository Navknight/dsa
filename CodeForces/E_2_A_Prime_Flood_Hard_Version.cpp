#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
const int N = 300000;

vector<int> spf(N + 1);
vector<int> off(N + 2);  // stuck points of u live in ys/val[off[u], off[u+1])
vector<int> ys, val;

// all y in (u, N] whose primes all divide u
void gen(const vector<int> &ps, int i, long long cur, int u, vector<int> &out)
{
    if (i == (int)ps.size())
    {
        if (cur > u)
            out.push_back(cur);
        return;
    }
    for (long long x = cur; x <= N; x *= ps[i])
        gen(ps, i + 1, x, u, out);
}

// g(u, v): best common value for pair u <= v
int g(int u, int v)
{
    auto b = ys.begin() + off[u], e = ys.begin() + off[u + 1];
    auto it = upper_bound(b, e, v);
    if (it == b)
        return u;
    return val[it - 1 - ys.begin()];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= N; i++)
        if (!spf[i])
            for (int j = i; j <= N; j += i)
                if (!spf[j])
                    spf[j] = i;

    vector<int> ps, tmp;
    for (int u = 1; u <= N; u++)
    {
        off[u] = ys.size();
        ps.clear();
        for (int x = u; x > 1; x /= spf[x])
            if (ps.empty() || ps.back() != spf[x])
                ps.push_back(spf[x]);
        tmp.clear();
        if (!ps.empty())
            gen(ps, 0, 1, u, tmp);
        sort(tmp.begin(), tmp.end());
        for (int y : tmp)
        {
            // stuck at y: u must drop along with it
            ys.push_back(y);
            val.push_back(0);
        }
        off[u + 1] = ys.size();
        for (int k = off[u]; k < off[u + 1]; k++)
            val[k] = g(u - 1, ys[k] - 1);
    }

    vector<long long> pw(N + 1, 1), ipw(N + 1, 1);
    const long long inv2 = (MOD + 1) / 2;
    for (int i = 1; i <= N; i++)
    {
        pw[i] = pw[i - 1] * 2 % MOD;
        ipw[i] = ipw[i - 1] * inv2 % MOD;
    }

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

        // S[k] = sum over hi <= k of (2^cnt[hi] - 1) * 2^pre[hi-1]
        vector<long long> S(n + 1, 0);
        for (int v = 1; v <= n; v++)
            S[v] = (S[v - 1] + (pw[cnt[v]] - 1) * pw[pre[v - 1]]) % MOD;
        auto rng = [&](int l, int r) { return (S[r] - S[l - 1] + MOD) % MOD; }; // hi in [l, r]

        long long ans = 0;
        for (int lo = 1; lo <= n; lo++)
        {
            if (!cnt[lo])
                continue;
            long long wl = pw[cnt[lo]] - 1;
            ans = (ans + wl * lo) % MOD;

            // g(lo, hi) is constant between consecutive stuck points of lo
            long long sum = 0;
            int from = lo + 1, cur = lo;
            for (int k = off[lo]; k < off[lo + 1] && ys[k] <= n; k++)
            {
                if (from <= ys[k] - 1)
                    sum = (sum + cur * rng(from, ys[k] - 1)) % MOD;
                from = ys[k];
                cur = val[k];
            }
            if (from <= n)
                sum = (sum + cur * rng(from, n)) % MOD;

            ans = (ans + wl * ipw[pre[lo]] % MOD * sum) % MOD;
        }

        cout << ans << "\n";
    }
}
