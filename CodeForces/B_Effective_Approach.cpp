#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr[x-1] = i;
    }

    int m;
    cin>>m;
    long long f = 0, b = 0;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        int in = arr[--t];
        f += in+1;
        b += n + 1 - (in+1);
    }

    cout << f << " " << b << endl;
}