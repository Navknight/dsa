#include <bits/stdc++.h>

using namespace std;

//Recursive Solution
int lcs(int n, int m, string s1, string s2)
{
    if (n == 0 || m == 0)
        return 0;
    else
    {
        if (s1[n - 1] == s2[m - 1])
            return 1 + lcs(n - 1, m - 1, s1, s2);
        else
            return max(lcs(n - 1, m, s1, s2), lcs(n, m - 1, s1, s2));
    }
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        cout << lcs(n, m, s1, s2) << endl;
    }
    return 0;
}