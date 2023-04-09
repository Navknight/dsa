#include <bits/stdc++.h>

using namespace std;

int dfs(int headID, vector<int> &informTime, unordered_map<int, vector<int>> &m)
{
    int max_time = 0;
    for (int child : m[headID])
    {
        max_time = max(max_time, dfs(child, informTime, m));
    }
    return informTime[headID] + max_time;
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        if (i == headID)
        {
            continue;
        }
        m[manager[i]].push_back(i);
    }
    return dfs(headID, informTime, m);
}

int main()
{
    int n = 6;
    int headID = 2;
    vector<int> manager = {2, 2, -1, 2, 2, 2};
    vector<int> informTime = {0, 0, 1, 0, 0, 0};
    cout << numOfMinutes(n, headID, manager, informTime) << endl;
    return 0;
}