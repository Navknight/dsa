#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int l = s.size();

    string sr = "";
    for (int i = 0; i < l; i++)
        sr = s[i] + sr;

    cout << sr << endl;

    vector<vector<int>> t(l + 1, vector<int>(l + 1));
    for (int i = 0; i < l + 1; i++)
    {
        for (int j = 0; j < l + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (s[i - 1] == sr[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    cout << t[l][l];

    return 0;
}