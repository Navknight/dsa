#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    int max = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    if (t[i][j] > max)
                        max = t[i][j];
                }
                else
                    t[i][j] = 0;
            }
        }
    }
    return max;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        cout << longestCommonSubstr(s1, s2, n, m) << endl;
    }
}