#include <bits/stdc++.h>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int mul = 1;
    int ans = 0;
    if (k <= 1)
        return ans;
    int left = 0, right = 0;
    while (right < nums.size())
    {
        mul *= nums[right];

        while (mul >= k)
        {
            mul /= nums[left];
            left++;
        }

        ans += right - left + 1;
        right++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3};
    int k = 19;
    cout << numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}