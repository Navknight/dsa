#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int ans = 0;
        float golden = (1 + sqrt(5)) / 2;
        for (int b = b1; b <= b2; b++)
        {
            if (float(a1) > golden * b || (golden - 1) * b > float(a2))
                ans += (a2 - a1 + 1);
            else
            {
                ans += max(0, int(float(a2) - floor(golden * b)));
                ans += max(0, int(floor((golden - 1) * b - float(a1) + 1)));
            }
        }
        cout << ans << endl;
    }
    return 0;
}