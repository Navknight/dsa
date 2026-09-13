#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> present(26, false);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        if (c >= 'A' && c <= 'Z')
            present[c - 'A'] = true;
        else
            present[c - 'a'] = true;
    }

    for (auto i : present)
    {
        if (!i)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}