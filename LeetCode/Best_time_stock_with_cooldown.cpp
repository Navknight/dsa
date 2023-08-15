#include <bits/stdc++.h>

using namespace std;

int help(vector<int> &prices, int i, int prev, int profit)
{
    if (i >= prices.size())
        return profit;
    else
    {
        if (prev == -1)
            return max(help(prices, i + 1, prices[i], profit), help(prices, i + 1, prev, profit));
        else
        {
            if (prices[i] > prev)
                return max(help(prices, i + 2, -1, profit + prices[i] - prev), help(prices, i + 1, prev, profit));
            else
                return help(prices, i + 1, prev, profit);
        }
    }
}

int maxProfit(vector<int> &prices)
{
    return help(prices, 0, -1, 0);
}

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}