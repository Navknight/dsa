#include <bits/stdc++.h>

using namespace std;

int minOperations(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (j == 0 || i == 0)
                t[i][j] = 0;
            else
            {
                if (str1[i - 1] == str2[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    int l = t[n][m];

    return ((l == m) ? (n - l) : (n - l + m - l));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        cout << minOperations(s1, s2) << "\n";
    }
    return 0;
}
