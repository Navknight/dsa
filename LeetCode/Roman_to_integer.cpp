#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s)
{
    unordered_map<string, int> table = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}};

    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i < s.size() - 1)
        {
            string sub = s.substr(i, 2);
            if (table.find(sub) != table.end())
            {
                ans += table[sub];
                i++;
            }
            else
            {
                ans += table[s.substr(i, 1)];
            }
        }

        else
        {
            ans += table[s.substr(i, 1)];
        }
    }

    return ans;
}

int main()
{
    string s = "DCXXI";
    cout << romanToInt(s) << endl;
    return 0;
}