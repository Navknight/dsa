#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> t(n + 1, vector<int>(3, 0));
    // 2 - we have 2 left
    // 1 - we have one left
    // 0 - we can't do anything

    for (int i = n - 1; i >= 0; i--)
    {
    }
}

int main()
{
    vector<int> prices = {};
    cout << maxProfit << (prices) << endl;
    return 0;
}