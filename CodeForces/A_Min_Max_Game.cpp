#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int count1 = 0, count0 = 0;

        for (auto i : a)
        {
            if (i == 1)
                count1++;
            else
                count0++;
        }

        if (count1 >= count0)
            cout << "Bessie";
        else
            cout << "Elsie";
        cout << endl;
    }
}