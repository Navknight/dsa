#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> dragons(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dragons[i].first >> dragons[i].second;
    }

    sort(dragons.begin(), dragons.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first < b.first; });

    for (int i = 0; i < n; i++)
    {
        if (dragons[i].first < s)
            s += dragons[i].second;
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}