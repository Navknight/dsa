#include <bits/stdc++.h>

using namespace std;

int minDistance(string word1, string word2)
{
    int n = word1.size(), m = word2.size();

    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
            {
                if (word1[i - 1] == word2[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = 0;
            }
        }
    }

    
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string word1, word2;
    cin >> word1 >> word2;

    cout << minDistance(word1, word2);

    return 0;
}