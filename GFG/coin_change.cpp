#include <bits/stdc++.h>

using namespace std;

long long int count(int coins[], int N, int sum)
{
    vector<vector<long long int>> t(N+1, vector<long long int>(sum+1));
    for (int i = 0; i < N+1 ; i++) {
        for (int j = 0; j < sum+1 ; j++) {
            if(i == 0)
                t[i][j] = 0;
            if(j == 0)
                t[i][j] = 1;
            if(i == 0 || j == 0)
                continue;
            else if(coins[i-1] <= j){
                t[i][j] = t[i][j - coins[i-1]] + t[i-1][j];
            }
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[N][sum];
}

int main()
{
    int n, sum;
    cin >> n >> sum;

    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << count(coins, n, sum) << endl;
    return 0;
}