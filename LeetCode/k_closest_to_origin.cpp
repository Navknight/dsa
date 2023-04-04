#include <bits/stdc++.h>

using namespace std;

float distance(vector<int> coord)
{
    return sqrt(pow(coord[0], 2) + pow(coord[1], 2));
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    vector<float> dist;
    for (auto c : points)
        dist.push_back(distance(c));
    while (k--)
    {
        float min = INT32_MAX;
        int ind = 0;
        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] < min)
            {
                min = dist[i];
                ind = i;
            }
        }
        ans.push_back(points[ind]);
        dist[ind] = INT32_MAX;
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