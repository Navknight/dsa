#include <bits/stdc++.h>

using namespace std;

int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    vector<unordered_map<int, int>> t(n);
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            if (t[j].find(diff) != t[j].end())
                t[i][diff] = t[j][diff] + 1;
            else
                t[i][diff] = 2;
            maxi = max(maxi, t[i][diff]);
        }
    }

    return maxi;
}

int main()
{
    vector<int> nums = {20, 1, 15, 3, 10, 5, 8};
    cout << longestArithSeqLength(nums) << endl;
    return 0;
}