#include <bits/stdc++.h>

using namespace std;

int knapsack(int val[], int wt[], int W, int n)
{

    int t[n + 1][W + 1]; // 2D table for dynamic programming

    // initialization
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
                t[i][j] = -1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][W]; // maximum value in the knapsack
}

int main()
{
    int wt[] = {7, 10, 2, 4};
    int val[] = {28, 60, 24, 28};

    cout << knapsack(val, wt, 13, 4) << endl;
    return 0;
}