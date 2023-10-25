#include <bits/stdc++.h>

using namespace std;

vector<int> construct(int n, int c, int m)
{
    if (n == 1)
        return vector<int> (1, m);
    else
    {
        if (c - 1 >= n - 2 && c - 1 <= (n * (n - 1)) / 2 - 1)
        {
            vector<int> res = construct(n - 1, c - 1, m + 1);
            res.insert(res.begin(), m);
            return res;
        }
        else
        {
            int delta = c - (n * (n - 1) / 2 - 1);
            vector<int> y = construct(n - 1, c - delta, m + 1);
            vector<int>::iterator end = y.begin();
            advance(end, delta - 1);
            reverse(y.begin(), end);
            y.insert(end, m);
            return y;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;

        if (c < n - 1 || c > n * (n + 1) / 2)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        else
        {
            vector<int> a = construct(n, c, 1);
            for (int i : a)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}