#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> a(n, false);

    int p;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        a[x-1] = true;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int y;
        cin >> y;
        a[y-1] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!a[i - 1])
        {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }
    cout << "I become the guy." << endl;
}