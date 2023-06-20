#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> r(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> r[i];
        n = n - r[i];
        if (n <= 0)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    for (int i = 0; n > 0; i++)
    {
        n = n - r[i % 7];
        if (n <= 0)
        {
            cout << i % 7 + 1 << endl;
            return 0;
        }
    }
}