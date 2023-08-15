#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> t(n + 1, vector<int>(2, 0));

    // 0 we can sell
    // 1 we can buy

    for (int i = n - 1; i >= 0; i--)
    {
        t[i][0] = max(prices[i] - fee + t[i + 1][1], t[i + 1][0]);
        t[i][1] = max(-prices[i] + t[i + 1][0], t[i + 1][1]);
    }

    return t[0][1];
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << maxProfit(prices, 2);
    return 0;
}