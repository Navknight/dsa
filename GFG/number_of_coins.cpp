#include <bits/stdc++.h>

using namespace std;

int minCoins(int coins[], int M, int V)
{
    vector<vector<int>> t(M + 1, vector<int>(V + 1));
    for (int i = 0; i < M + 1; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = INT32_MAX - 1;
                continue;
            }
            if (j == 0)
            {
                t[i][j] = 0;
                continue;
            }
            if (i == 1)
            {
                if (j % coins[i - 1] == 0)
                    t[i][j] = j / coins[i - 1];

                else
                    t[i][j] = INT32_MAX - 1;
            }
            else if (coins[i - 1] <= j)
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);

            else
                t[i][j] = t[i - 1][j];
        }
    }
    return (t[M][V] >= INT32_MAX - 1) ? -1 : t[M][V];
}

int main()
{
    int M, V;
    cin >> V >> M;

    int coins[M];
    for (int i = 0; i < M; i++)
    {
        cin >> coins[i];
    }

    cout << minCoins(coins, M, V) << endl;
    return 0;
}