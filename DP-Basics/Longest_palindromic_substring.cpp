#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = s.size();

    string ans = "";
    int max = 0;

    for (int i = 1; i < n; i++)
    {
        int l = i - 1;
        int r = i + 1;

        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                if (r - l + 1 > max)
                {
                    ans = s.substr(l, r - l + 1);
                    max = r - l + 1;
                    l--;
                    r++;
                }
                else
                {
                    l--;
                    r++;
                }
            }
            else
                break;
        }

        l = i - 1;
        r = i;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                if (r - l + 1 > max)
                {
                    ans = s.substr(l, r - l + 1);
                    max = r - l + 1;
                    l--;
                    r++;
                }
                else
                {
                    l--;
                    r++;
                }
            }
            else
                break;
        }
    }
    cout << ans << endl;
    return 0;
}