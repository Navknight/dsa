#include <bits/stdc++.h>

using namespace std;

string printLCS(string a, string b, int n, int m)
{
    vector<vector<int>> t(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (a[i - 1] == b[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = n, j = m;
    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            i--;
            j--;
            ans = a[i] + ans;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
                i--;
            else
                j--;
        }
    }

    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    cout << printLCS(a, b, n, m) << endl;

    return 0;
}