#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    sort(cost.begin(), cost.end());

    int profit = 0;
    for (int i = 0; i < m; i++)
    {
        if (cost[i] < 0)
            profit += cost[i];
    }

    cout << abs(profit) << endl;
    return 0;
}