#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<bool> check(n);
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if (nums[i] % 2 == 0)
                check[i] = true;
        }
        sort(nums.begin(), nums.end());
        bool printed = false;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                if (check[i] != 1)
                {
                    cout << "NO" << endl;
                    printed = true;
                    break;
                }
            }
            else
            {
                if (check[i] != 0)
                {
                    cout << "NO" << endl;
                    printed = true;
                    break;
                }
            }
        }

        if (!printed)
            cout << "YES" << endl;
    }
    return 0;
}