#include <bits/stdc++.h>

using namespace std;

// Recursive Solution
// int lcs(int n, int m, string s1, string s2)
// {
//     if (n == 0 || m == 0)
//         return 0;
//     else
//     {
//         if (s1[n - 1] == s2[m - 1])
//             return 1 + lcs(n - 1, m - 1, s1, s2);
//         else
//             return max(lcs(n - 1, m, s1, s2), lcs(n, m - 1, s1, s2));
//     }
// }

// Memorised Solution
// int dp[1001][1001];

// int lcs(int n, int m, string s1, string s2)
// {
//     if (n == 0 || m == 0)
//     {
//         dp[n][m] = 0;
//         return dp[n][m];
//     }
//     else
//     {
//         if (dp[n][m] == -1)
//         {
//             if (s1[n - 1] == s2[m - 1])
//                 dp[n][m] = 1 + lcs(n - 1, m - 1, s1, s2);
//             else
//                 dp[n][m] = max(lcs(n - 1, m, s1, s2), lcs(n, m - 1, s1, s2));
//         }
//         return dp[n][m];
//     }
// }

int lcs(int n, int m, string s1, string s2)
{
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (s1[i - 1] == s2[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[n][m];
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        // memset(dp, -1, sizeof(dp));
        cout << lcs(n, m, s1, s2) << endl;
    }
    return 0;
}