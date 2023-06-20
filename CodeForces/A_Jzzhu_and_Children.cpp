#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int last = -1;
    int turn = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int y = ceil(float(x) / float(m));

        if (y >= turn)
        {
            last = i + 1;
            turn = y;
        }
    }
    cout << last << endl;
}