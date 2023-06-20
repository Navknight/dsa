#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<bool>> grid(3, vector<bool>(3, 1));

    for (int i = 0; i < 9; i++)
    {
        int t;
        cin >> t;

        int col = i % 3;
        int row = i / 3;
        if (t % 2 != 0)
        {
            grid[row][col] = !grid[row][col];
            if (row + 1 < 3)
                grid[row + 1][col] = !grid[row + 1][col];
            if (col + 1 < 3)
                grid[row][col + 1] = !grid[row][col + 1];
            if (row > 0)
                grid[row - 1][col] = !grid[row - 1][col];
            if (col > 0)
                grid[row][col - 1] = !grid[row][col - 1];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}