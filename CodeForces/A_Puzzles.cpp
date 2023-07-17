#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;

    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int min = INT32_MAX;
    for (int i = 0; i + n - 1 < m; i++)
    {
        if (arr[i + n - 1] - arr[i] < min)
            min = arr[i + n - 1] - arr[i];
    }

    cout << min << endl;
    return 0;
}