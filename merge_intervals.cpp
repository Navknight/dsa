#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> merged;
    if (intervals.size() == 0)
    {
        return merged;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    for (auto it : intervals)
    {
        if (it[0] <= tempInterval[1])
        {
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else
        {
            merged.push_back(tempInterval);
            tempInterval = it;
        }
    }
    merged.push_back(tempInterval);
    return merged;
}

int main()
{
    vector<vector<int>> intervals = {{1, 4}, {2, 3}};
    vector<vector<int>> merged = merge(intervals);
    for (int i = 0; i < merged.size(); i++)
    {
        cout << merged[i][0] << " " << merged[i][1] << endl;
    }
    return 0;
}