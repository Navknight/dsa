#include <bits/stdc++.h>

using namespace std;

// Recursion
//  int minDistance(string word1, string word2)
//  {
//      int m = word1.size(), n = word2.size();
//      if (m == 0)
//          return n;
//      if (n == 0)
//          return m;
//      if (word1[m - 1] == word2[n - 1])
//          return minDistance(word1.substr(0, m - 1), word2.substr(0, n - 1));
//      else
//      {
//          int replace = minDistance(word1.substr(0, m - 1), word2.substr(0, n - 1));
//          int del = minDistance(word1.substr(0, m - 1), word2.substr(0, n));
//          int ins = minDistance(word1.substr(0, m), word2.substr(0, n - 1));

//         return 1 + min(min(replace, del), ins);
//     }
// }

// int minDistance(string word1, string word2)
// {
//     int m = word1.size(), n = word2.size();
//     vector<vector<int>> t(m + 1, vector<int>(n + 1));

//     for (int i = 0; i < m + 1; i++)
//     {
//         for (int j = 0; j < n + 1; j++)
//         {
//             if (i == 0)
//             {
//                 t[i][j] = j;
//                 continue;
//             }
//             if (j == 0)
//             {
//                 t[i][j] = i;
//                 continue;
//             }
//             if (word1[i - 1] == word2[j - 1])
//                 t[i][j] = t[i - 1][j - 1];
//             else
//             {
//                 t[i][j] = 1 + min(min(t[i - 1][j], t[i][j - 1]), t[i - 1][j - 1]);
//             }
//         }
//     }

//     return t[m][n];
// }
int minDistance(string word1, string word2)
{
    int m = word1.size(), n = word2.size();
    if(m == 0)
        return n;
    if(n == 0)
        return m;
    vector<int> prev(n + 1);
    for (int i = 0; i < n + 1; i++)
        prev[i] = i;
    vector<int> curr(n + 1);
    for (int i = 1; i < m + 1; i++)
    {
        curr[0] = i;
        for (int j = 1; j < n + 1; j++)
        {
            if(word1[i-1] == word2[j-1])
                curr[j] = prev[j-1];
            else
                curr[j] = 1 + min(min(prev[j-1], prev[j]), curr[j-1]);
        }
        prev = curr;
    }

    return curr[n];
}

int main()
{
    string word1, word2;
    // cin >> word1 >> word2;

    cout << minDistance("", "a");

    return 0;
}