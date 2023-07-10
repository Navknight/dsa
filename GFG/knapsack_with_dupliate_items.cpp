#include <bits/stdc++.h>

using namespace std;

// int knapSack(int N, int W, int val[], int wt[])
// {
//     if (W == 0 || N == 0)
//         return 0;
//     else if (wt[N - 1] <= W)
//     {
//         return max(val[N - 1] + knapSack(N, W - wt[N - 1], val, wt), knapSack(N - 1, W, val, wt));
//     }
//     else
//     {
//         return knapSack(N - 1, W, val, wt);
//     }
// }

int knapSack(int N, int W, int val[], int wt[]){
    vector<vector<int>> t(N+1, vector<int> (W+1));

    for (int i = 0; i < N+1 ; i++) {
        for (int j = 0; j < W+1 ; j++) {
            
        }
    }
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