#include <bits/stdc++.h>

using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> t(m, vector<int>(n, 0));
    t.back() = matrix.back();

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = matrix[i][j] + min(t[i + 1][j], min((j + 1 < n) ? t[i + 1][j + 1] : INT32_MAX, (j - 1 >= 0) ? t[i + 1][j - 1] : INT32_MAX));
        }
    }

    sort(t[0].begin(), t[0].end());
    return t[0][0];
}

int main()
{
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}