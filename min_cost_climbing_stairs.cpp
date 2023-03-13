#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size() - 1;
    cost.push_back(0);
    cost.push_back(0);
    for (int i = n; i >= 0; i--)
    {
        cost[i] += min(cost[i + 1], cost[i + 2]);
    }
    return min(cost[0], cost[1]);
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}
