#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> t;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        t[s]++;
    }
    int in = INT32_MIN;
    string ans = "";
    for (auto i : t)
    {
        if (i.second > in)
        {
            in = i.second;
            ans = i.first;
        }
    }
    cout << ans << endl;

    return 0;
}