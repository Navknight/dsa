#include <bits/stdc++.h>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    vector<int> t(triangle.back());
    for (int i = triangle.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j<= triangle[i].size() - 1; j++)
        {
            t[j] = triangle[i][j] + min(t[j], t[j+1]);
        }
    }
    return t[0];
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}