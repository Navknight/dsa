#include <bits/stdc++.h>

using namespace std;

int numDistinct(string s, string t)
{
    int m = s.size(), n = t.size();
    vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1));
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 1;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j] > 2147483647) ? 0 : dp[i - 1][j - 1] + dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;
    int sum = numDistinct(s, t);
    cout << sum << endl;
    return 0;
}