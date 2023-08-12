#include <bits/stdc++.h>

using namespace std;

int findLongestChain(vector<vector<int>> &pairs)
{
    int n = pairs.size();
    int max_length = 1;
    sort(pairs.begin(), pairs.end());
    vector<int> t(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pairs[j][0] > pairs[i][1])
            {
                t[i] = max(t[i], 1 + t[j]);
            }
        }
        max_length = max(max_length, t[i]);
    }
    return max_length;
}

int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });

    int n = pairs.size();
    int max_length = 1;
    int prev = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pairs[i][0] > prev)
        {
            max_length++;
            prev = pairs[i][1];
        }
    }

    return max_length;
}

int main()
{
    vector<vector<int>> pairs = {{1, 2},
                                 {2, 3},
                                 {3, 4}};
    cout << findLongestChain(pairs) << endl;
    return 0;
}