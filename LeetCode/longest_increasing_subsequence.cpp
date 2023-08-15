#include <bits/stdc++.h>

using namespace std;

// int help(vector<int> &nums, int n, int maxi)
// {
//     if (n == 0)
//         return 0;
//     else
//     {
//         if (nums[n - 1] < maxi)
//             return max(help(nums, n - 1, nums[n - 1]) + 1, help(nums, n - 1, maxi));
//         else
//             return help(nums, n - 1, maxi);
//     }
// }

// int lengthOfLIS(vector<int> &nums)
// {
//     // return 0;
//     return help(nums, nums.size(), INT32_MAX);
// }

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int maxi = INT32_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (nums[i] < nums[j])
                temp = max(temp, ans[j] + 1);
        }
        ans[i] = temp;
        maxi = max(temp, maxi);
    }

    return maxi;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}