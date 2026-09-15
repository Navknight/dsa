#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> diff(n+1, 0);
    for (int i = 0; i < q; i++)
    {
        long long l, r;
        cin >> l >> r;
        l--;
        r--;

        diff[l]++;
        diff[r + 1]--;
    }

    for (int i = 1; i <= n; i++)
        diff[i] += diff[i - 1];
    sort(a.begin(), a.end());
    sort(diff.begin(), diff.begin() + n);

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * diff[i];

    cout << sum << endl;
    return 0;
}