#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> a;

int mincost(vector<int> &cost, int i)
{
    if (i < 0)
        return 0;
    
    if(a.find(i) != a.end())
        return a[i];
    
    int cost1 = cost[i] + mincost(cost, i - 1);
    int cost2 = cost[i] + mincost(cost, i - 2);
    a[i] = min(cost1, cost2);
    return a[i];
}

int minCostClimbingStairs(vector<int> &cost)
{
    return min(mincost(cost, cost.size() - 1), mincost(cost, cost.size() - 2));
}

int main()
{
    vector<int> cost = {10, 15, 20, 40, 70, 80, 50, 1, 2, 100, 1, 0, 1, 1};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}
