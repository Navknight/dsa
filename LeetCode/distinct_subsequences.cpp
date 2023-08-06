#include <bits/stdc++.h>

using namespace std;

int numDistinct(string s, string t)
{
    int m = s.size();
    int n = t.size();
    vector<unsigned long long int> dp(n + 1);

    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        unsigned long long int prev = 1;
        for (int j = 1; j <= n; j++)
        {
            long long int temp = dp[j];
            if (s[i - 1] == t[j - 1])
                dp[j] += prev;
            prev = temp;
        }
    }

    return dp[n];
}

int main()
{
    string s, t;
    cin >> s >> t;
    int sum = numDistinct(s, t);
    cout << sum << endl;
    return 0;
}