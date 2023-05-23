#include <bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    int time = -1;
    while (!q.empty())
    {
        int s = q.size();
        time++;
        for (int i = 0; i < s; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                grid[x - 1][y] = 2;
                q.push({x - 1, y});
            }
            if (x + 1 < n && grid[x + 1][y] == 1)
            {
                grid[x + 1][y] = 2;
                q.push({x + 1, y});
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                grid[x][y - 1] = 2;
                q.push({x, y - 1});
            }
            if (y + 1 < m && grid[x][y + 1] == 1)
            {
                grid[x][y + 1] = 2;
                q.push({x, y + 1});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    if (time == -1)
        return 0;
    return time;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid) << endl;
    return 0;
}
