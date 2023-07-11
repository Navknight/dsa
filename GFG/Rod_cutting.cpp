#include <bits/stdc++.h>

using namespace std;

int cutRod(int price[], int n)
{
    vector<vector<int>> t(n+1, vector<int>(n+1));
    for (int i = 0; i < n+1 ; i++) {
        for (int j = 0; j < n+1 ; j++) {
            if(i == 0 || j ==0){
                t[i][j] = 0;
                continue;
            }
            else if(i <= j){
                t[i][j] = max(price[i-1] + t[i][j-i], t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][n];
}

int main()
{
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    cout << cutRod(price, n) << endl;
    return 0;
}