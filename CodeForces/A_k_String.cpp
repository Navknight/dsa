#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    string in;
    cin >> in;
    vector<int> f(26);
    int count = in.size();

    for (int i = 0; i < count; i++)
    {
        f[in[i] - 'a']++;
    }
    string out = "";
    vector<char> ch;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] != k && f[i] != 0)
        {
            cout << -1 << endl;
            return 0;
        }
        else if (f[i] > 0)
            ch.push_back(i + 'a');
    }

    while (k)
    {
        for (int i = 0; i < ch.size(); i++)
        {
            out += ch[i];
        }
    }

    cout << out << endl;
    return 0;
}