#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int max = 1;
        int ind = 1;
        for (int i = 1; i < n; i++)
        {
            if (abs(arr[i] - arr[i - 1]) <= k)
                ind++;
            else
            {
                if (ind > max)
                {
                    max = ind;
                    
                }
                ind = 1;
            }
        }
        if(ind > max)
            max = ind;
        cout << n - max << endl;
    }
    return 0;
}