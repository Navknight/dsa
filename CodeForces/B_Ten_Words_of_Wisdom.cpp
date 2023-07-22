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

        vector<pair<int, int>> arr;
        int max = INT32_MIN;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            int l, q;
            cin >> l >> q;
            if (l <= 10)
            {
                arr.push_back({l, q});
                if (q > max)
                {
                    max = q;
                    ind = i + 1;
                }
            }
        }

        cout << ind << endl;
    }
    return 0;
}