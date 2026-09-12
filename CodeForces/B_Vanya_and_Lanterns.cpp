#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    double dist = 0.0;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        double d = a[i] - last;
        if (i == 0)
            dist = max(dist, d);
        else
            dist = max(dist, d / 2);
        last = a[i];
    }
    dist = max(dist, (double)(l - last));

    cout << fixed << setprecision(10) << dist << endl;
}