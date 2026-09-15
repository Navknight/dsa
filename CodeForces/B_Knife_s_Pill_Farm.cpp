#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        priority_queue<long long> maxheap;
        long long S = 0;
        long long best = LLONG_MIN;

        for (int p = 0; p < n; p++)
        {
            if ((int)maxheap.size() >= m - 1)
            {
                long long score = (long long)m * a[p] - S;
                best = max(best, score);
            }
            if ((int)maxheap.size() < (m - 1))
            {
                maxheap.push(a[p]);
                S += a[p];
            }
            else if (m - 1 > 0 && a[p] < maxheap.top())
            {
                S += a[p] - maxheap.top();
                maxheap.pop();
                maxheap.push(a[p]);
            }
        }

        cout << best << endl;
    }
}