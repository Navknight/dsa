#include <bits/stdc++.h>

using namespace std;

// int help(vector<int> &prices, int i, int prev, int profit)
// {
//     if (i >= prices.size())
//         return profit;
//     else
//     {
//         if (prev == -1)
//             return max(help(prices, i + 1, prices[i], profit), help(prices, i + 1, prev, profit));
//         else
//         {
//             if (prices[i] > prev)
//                 return max(help(prices, i + 2, -1, profit + prices[i] - prev), help(prices, i + 1, prev, profit));
//             else
//                 return help(prices, i + 1, prev, profit);
//         }
//     }
// }

// int maxProfit(vector<int> &prices)
// {
//     return help(prices, 0, -1, 0);
// }

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> t(n+1, vector<int> (2));

    //0 is for holding stock
    //1 is for buying

    t[0][0] = 0;
    t[0][1] = -prices[0];

    for(int i  = 1; i < n+1; i++){
        
    }
}

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}