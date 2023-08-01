#include <bits/stdc++.h>

using namespace std;

unordered_map<string, bool> memo;

bool check(string sub, vector<string> &wordDict)
{
    int n = wordDict.size();
    for (int i = 0; i < n; i++)
    {
        if (wordDict[i] == sub)
            return true;
    }

    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    memo.clear();
    return wordBreakHelp(s, wordDict);
}

bool wordBreakHelp(string s, vector<string> &wordDict)
{
    int n = s.size();
    if (n == 0)
        return true;
    else
    {
        if (memo.find(s) != memo.end())
            return memo[s];
        else
        {
            for (string word : wordDict)
            {
                if (word.size() <= n)
                    if (check(s.substr(0, word.size()), wordDict) && wordBreakHelp(s.substr(word.size(), n - word.size()), wordDict))
                        return memo[s] = true;
            }
            return memo[s] = false;
        }
    }
    return memo[s] = false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> wordDict(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wordDict[i];
    }

    cout << wordBreak(s, wordDict);
    return 0;
}