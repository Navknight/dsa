#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = n;
    int maxl = INT_MIN, maxi = -1;
    int minr = INT_MAX, mini = -1;

    while (count--)
    {
        int curr;
        cin >> curr;
        if (curr > maxl)
        {
            maxl = curr;
            maxi = n - count;
        }
        if (curr <= minr)
        {
            minr = curr;
            mini = n - count;
        }
    }

    if (maxi < mini)
    {
        cout << maxi + n - mini - 1 << endl;
    }
    else
    {
        cout << maxi + n - mini - 2 << endl;
    }
}