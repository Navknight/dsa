#include <bits/stdc++.h>
using namespace std;

int n;

long long cost(const vector<int> &ps)
{
    long long cnt[3] = {0, 0, 0};
    int q = 0, prev = 0;
    for (int p : ps)
    {
        cnt[q] += p - prev;
        q = (q + (p % 2 == 0 ? 1 : 2)) % 3;
        prev = p;
    }
    cnt[q] += n + 1 - prev;
    long long f = 0;
    for (int r = 0; r < 3; r++)
        f += cnt[r] * (cnt[r] - 1) / 2;
    return f;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        set<int> cand;
        for (int c : {1, n / 3, 2 * n / 3})
            for (int d = -4; d <= 4; d++)
                if (c + d >= 1 && c + d <= n)
                    cand.insert(c + d);
        vector<int> v(cand.begin(), cand.end());
        int k = v.size();

        vector<int> best = {};
        long long bestF = cost(best);
        auto tryIt = [&](vector<int> ps)
        {
            long long f = cost(ps);
            if (f < bestF)
                bestF = f, best = ps;
        };
        for (int a = 0; a < k; a++)
        {
            tryIt({v[a]});
            for (int b = a + 1; b < k; b++)
            {
                tryIt({v[a], v[b]});
                for (int c = b + 1; c < k; c++)
                    tryIt({v[a], v[b], v[c]});
            }
        }

        string s(n, '0');
        for (int p : best)
            s[p - 1] = '1';
        cout << s << '\n';
    }
}
