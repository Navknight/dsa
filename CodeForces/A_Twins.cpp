#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }

    int count = 0, sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        count++;
        sum += a[i];

        if (sum > pre[i])
        {
            cout << count << endl;
            return 0;
        }
    }
}