#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> m;
    for (auto str : strs)
    {
        string t = str;
        sort(t.begin(), t.end());
        m[t].push_back(str);
    }

    vector<vector<string>> ans;

    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (auto v : res)
    {
        for (auto s : v)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}