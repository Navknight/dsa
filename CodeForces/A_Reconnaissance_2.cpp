#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int prev;
    cin >> prev;
    int first = prev;
    int i1, i2;
    int min = INT32_MAX;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        if (abs(prev - x) < min)
        {
            i1 = i;
            i2 = i + 1;
            min = abs(prev - x);
            prev = x;
        }
        else
        {
            prev = x;
        }
    }
    if (abs(prev - first) < min)
    {
        i1 = 1;
        i2 = n;
    }
    cout << i1 << " " << i2 << endl;
    return 0;
}