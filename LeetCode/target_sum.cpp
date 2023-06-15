#include <bits/stdc++.h>

using namespace std;

int findTargetSumWays(vector<int> &nums, int target)
{
    int range = 0;
    for (auto i : nums)
        range += i;
    target = abs(target);
    if ((range + target) % 2 != 0)
        return 0;

    int sum = (target + range) / 2;
    vector<vector<int>> t(nums.size() + 1, vector<int>(sum + 1, 0));
    t[0][0] = 1;

    for (int i = 1; i < nums.size() + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (nums[i - 1] <= j)
                t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[nums.size()][sum];
}

int main()
{
    vector<int> nums = {100};
    int target = -200;
    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}