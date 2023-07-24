#include <bits/stdc++.h>

using namespace std;

int knapSack(int N, int W, int val[], int wt[])
{
    if (W == 0 || N == 0)
        return 0;
    else if (wt[N - 1] <= W)
    {
        return max(val[N - 1] + knapSack(N, W - wt[N - 1], val, wt), knapSack(N - 1, W, val, wt));
    }
    else
    {
        return knapSack(N - 1, W, val, wt);
    }
}

vector<vector<int>> t(1001, vector<int>(1001, -1));
int knapSack(int N, int W, int val[], int wt[]){
    if(N== 0 || W == 0){
        t[N][W] = 0;
        return t[N][W];
    }
    else if(wt[N-1] <= W){
        if(t[N][W] == -1){
            t[N][W] = max(val[N-1] + knapSack(N, W-wt[N-1], val, wt), knapSack(N-1, W, val, wt));
        }
        return t[N][W];
    }
    else{
        t[N][W] = knapSack(N-1, W, val, wt);
        return t[N][W];
    }
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> t(N + 1, vector<int>(W + 1));

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
                continue;
            }
            else if(wt[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[N][W];
}

int main()
{
    int N, W;
    cin >> N >> W;
    int val[N], wt[N];
    for (int i = 0; i < N; i++)
        cin >> val[i];
    for (int i = 0; i < N; i++)
        cin >> wt[i];

    cout << knapSack(N, W, val, wt) << endl;
    return 0;
}