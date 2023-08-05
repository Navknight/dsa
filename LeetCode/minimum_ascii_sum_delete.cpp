#include <bits/stdc++.h>

using namespace std;

int asciisum(string s)
{
    int sum = 0;
    for (char i : s)
        sum += i;
    return sum;
}
int minimumDeleteSum(string s1, string s2)
{
    vector<vector<int>> t(s1.size() + 1, vector<int>(s2.size() + 1));
    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (s1[i - 1] == s2[j - 1])
                    t[i][j] = t[i - 1][j - 1] + s1[i - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return asciisum(s1) + asciisum(s2) - 2 * t[s1.size()][s2.size()];
}

int main()
{
    string s1 = "delete";
    string s2 = "leet";
    cout << minimumDeleteSum(s1, s2);
    return 0;
}
