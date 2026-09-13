#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if (m <= n)
    {
        cout << n - m << endl;
        return 0;
    }
    else
    {
        int ops = 0;
        while (m > n)
        {
            if (m % 2 != 0)
            {
                ops++;
                m++;
            }
            m /= 2;
            ops++;
        }
        cout << ops + n - m << endl;
    }
}