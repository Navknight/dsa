#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, H;
        cin >> n >> m >> k >> H;

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;

            if (abs(H - h) % k == 0 && abs(H - h) / k < m && h != H)
                count++;
        }

        cout << count << endl;
    }
    return 0;
}