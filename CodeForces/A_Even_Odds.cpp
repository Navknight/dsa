#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    if (n % 2 == 0)
    {
        if (k <= n / 2)
        {
            k = 1 + 2 * (k - 1);
        }
        else
        {
            k = 2 + 2 * (k - 1 - n / 2);
        }
    }
    else
    {
        if (k <= (n + 1) / 2)
        {
            k = 1 + 2 * (k - 1);
        }
        else
        {
            k = 2 + 2 * (k - 1 - (n + 1) / 2);
        }
    }
    cout << k << endl;
}