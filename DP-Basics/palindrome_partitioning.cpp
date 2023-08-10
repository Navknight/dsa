#include <bits/stdc++.h>

using namespace std;



vector<vector<string>> partition(string s)
{
}

int main()
{
    vector<vector<string>> p = partition("aab");
    for (auto i : p)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}