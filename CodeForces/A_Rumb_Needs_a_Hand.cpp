#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> b = a;
        sort(b.begin(), b.end());

        vector<int> notMatch;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                notMatch.push_back(i);
            }
        }

        bool ok = true;
        int l = 0, r = notMatch.size() - 1;
        while (l < r)
        {
            if (a[notMatch[l]] != b[notMatch[r]] || a[notMatch[r]] != b[notMatch[l]])
            {
                ok = false;
                break;
            }
            l++;
            r--;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}