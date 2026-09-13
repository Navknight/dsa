#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;

    int cap = INT_MIN;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        curr = curr - a + b;
        cap = max(cap, curr);
    }

    cout << cap << endl;
}