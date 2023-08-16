#include <bits/stdc++.h>

using namespace std;

int numSquares(int n)
{
    int root = sqrt(n);
    vector<vector<int>> t(root + 1, vector<int>(n + 1, INT32_MAX - 1));

    for (int i = 0; i < root + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (j == 0 || i == 0)
                t[i][j] = 0;
            else if (i == 1)
                t[i][j] = ((j % (i * i) == 0) ? (j / (i * i)) : INT32_MAX - 1);
            else
            {
                if ((i * i) <= j)
                    t[i][j] = min(t[i][j - (i * i)] + 1, t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[root][n];
}

int main()
{
    cout << numSquares(12) << endl;
    return 0;
}