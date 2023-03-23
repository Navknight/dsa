#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    if (m < n)
        return false;
    vector<int> a(26, 0);
    for (int i = 0; i < n; i++)
    {
        a[s1[i] - 'a']++;
    }
    for (int i = 0; i + n <= m; i++)
    {
        string s = s2.substr(i, n);
        vector<int> a1(26, 0);
        for (int j = 0; j < n; j++)
        {
            a1[s[j] - 'a']++;
        }
        if (a == a1)
            return true;
    }
    return false;
}

int main()
{
    string s1 = "adc";
    string s2 = "dcda";
    cout << checkInclusion(s1, s2);
    return 0;
}