#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str, int start, int end)
{
    for (int i = start; i < (end - start + 1) / 2; i++)
        if (str[i] != str[end - i])
            return false;
    return true;
}

int help(string str, int i, int j, vector<vector<int>> &t)
{
    if (i >= j || isPalindrome(str, i, j))
        return t[i][j] = 0;
    if (t[i][j] != -1)
        return t[i][j];
    int mini = INT32_MAX;
    for (int k = i; k < j; k++)
    {
        mini = min(help(str, i, k, t) + help(str, k + 1, j, t) + 1, mini);
    }

    return t[i][j] = mini;
}

int palindromicPartition(string str)
{
    int n = str.size();
    vector<vector<int>> t(n + 1, vector<int>(n + 1, -1));
    return help(str, 0, str.size() - 1, t);
}

int main()
{
    int p = palindromicPartition("ababbbabbababa");
    cout << p << endl;
    return 0;
}