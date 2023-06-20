#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> g(n);

    for (int i = 0; i < n; i++)
    {
        cin >> g[i].first;
        cin >> g[i].second;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool u = false;
        bool d = false;
        bool r = false;
        bool l = false;
        for (int j = 0; j < n; j++)
        {
            if (g[j].first > g[i].first && g[j].second == g[i].second)
                l = true;
            else if (g[j].first < g[i].first && g[j].second == g[i].second)
                r = true;
            else if (g[j].first == g[i].first && g[j].second > g[i].second)
                d = true;
            else if (g[j].first == g[i].first && g[j].second < g[i].second)
                u = true;
            if (l && r && d && u)
            {
                count++;
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}