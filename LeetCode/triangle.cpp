#include <bits/stdc++.h>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    vector<int> dp(triangle.back());
    int n = triangle.size();
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        }
    }
    return dp[0];
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}