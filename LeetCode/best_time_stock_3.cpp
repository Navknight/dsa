#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy == 0)
                    curr[buy][cap] = max(-prices[i] + prev[1][cap], prev[0][cap]);
                if(buy == 1)
                    curr[buy][cap] = max(prices[i] + prev[0][cap - 1], prev[1][cap]);
            }
        }
        prev = curr;
    }

    return curr[0][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}