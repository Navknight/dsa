#include<bits/stdc++.h>

using namespace std;

bool isRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
{
    int n = mat.size();
    int m = mat[0].size();
    int n1 = target.size();
    int m1 = target[0].size();
    if (n != n1 || m != m1)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] != target[i][j])
            {
                return false;
            }
        }
    }
    return true;
}