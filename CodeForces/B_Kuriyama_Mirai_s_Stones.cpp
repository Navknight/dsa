#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> s = a;
    sort(s.begin(), s.end());

    vector<long long> prefA(n + 1, 0), prefS(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefA[i + 1] = prefA[i] + a[i];
        prefS[i + 1] = prefS[i] + s[i];
    }

    int m;
    cin >> m;

    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1)
            cout << prefA[r] - prefA[l - 1] << endl;
        else
            cout << prefS[r] - prefS[l - 1] << endl;
    }
}