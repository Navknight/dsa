#include <bits/stdc++.h>

using namespace std;

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b)
         {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0]; });

    int n = envelopes.size();
    vector<int> t;

    for (int i = 0; i < n; i++)
    {
        if (t.size() == 0 || envelopes[i][1] > t[t.size() - 1])
            t.push_back(envelopes[i][1]);
        else
        {
            auto it = lower_bound(t.begin(), t.end(), envelopes[i][1]);
            *it = envelopes[i][1];
        }
    }

    return t.size();
}

int main()
{
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << maxEnvelopes(envelopes) << endl;
    return 0;
}