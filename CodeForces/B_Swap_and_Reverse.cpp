#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        if (k % 2 == 0)
        {
            sort(s.begin(), s.end());
            cout << s << endl;
        }
        else
        {
            vector<char> odd, even;
            for (int i = 0; i < s.size(); i++)
            {
                if (i % 2 == 0)
                    even.push_back(s[i]);
                else
                    odd.push_back(s[i]);
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            for (int i = 0; i < s.size(); i++)
            {
                cout << ((i % 2 == 0) ? even[i / 2] : odd[i / 2]);
            }
            cout << endl;
        }
    }
    return 0;
}