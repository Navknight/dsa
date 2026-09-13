#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int curr = 0, count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' == curr)
            count++;
        else
        {
            count = 1;
            curr = s[i] - '0';
        }

        if (count == 7)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}