#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    priority_queue < pair<int, pair<int, int>>> q;
    for (int i = 0; i < points.size(); i++)
    {
        q.push({pow(points[i][0], 2) + pow(points[i][1], 2), {points[i][0], points[i][1]}});
        if(q.size()>k)
            q.pop();
    }
    while(!q.empty()){
        vector<int> row;
        row.push_back(q.top().second.first);
        row.push_back(q.top().second.second);
        q.pop();
        ans.push_back(row);
        row.clear();
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{-5, 4}, {-6, -5}, {4, 6}};
    int k = 2;
    vector<vector<int>> ans = kClosest(points, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i][0] << " " << ans[i][1] << endl;
    return 0;
}