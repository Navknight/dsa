#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    bool white = false;
    vector<vector<char>> t(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '-')
            {
                cout << c;
                continue;
            }
            else
            {
                if (white)
                {
                    if (i > 0 && t[i - 1][j] == 'W')
                    {
                        t[i][j] = 'B';
                        cout << t[i][j];
                    }
                    else
                    {
                        t[i][j] = 'W';
                        white = !white;
                        cout << t[i][j];
                    }
                }
                else
                {
                    if (i > 0 && t[i - 1][j] == 'B')
                    {
                        t[i][j] = 'W';
                        cout << t[i][j];
                    }
                    else
                    {
                        t[i][j] = 'B';
                        white = !white;
                        cout << t[i][j];
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}