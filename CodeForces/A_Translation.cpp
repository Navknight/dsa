#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    if (strcmp((const char*)s.c_str(), (const char*)t.c_str()) == 0)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}