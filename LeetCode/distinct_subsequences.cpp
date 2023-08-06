#include <bits/stdc++.h>

using namespace std;

bool lcs(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
    for (int i = 0; i < s.size() + 1; i++)
    {
        for (int j = 0; j < t.size() + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return t.size() == dp[s.size()][t.size()];
}

int numDistinct(string s, string t, int sum)
{
    if (s.size() == t.size())
        return 1;
    int j = 0;
    while (j < s.size())
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (s[j] == t[i])
            {
                char c = s[j];

                s.erase(s.begin() + j);

                numDistinct(s, t, sum);

                sum = ((lcs(s, t)) ? sum + 1 : sum);

                s.insert(s.begin() + j, c);

                j++;
            }
        }
        j++;
    }
    return sum;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int sum = numDistinct(s, t, 0);
    cout << sum << endl;
    return 0;
}