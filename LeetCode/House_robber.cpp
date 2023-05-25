#include <bits/stdc++.h>

using namespace std;

int helper(vector<int> &nums, int index, vector<int> &memo)
// Memorisation
{

    if (index >= nums.size())

        return 0;

    if (memo[index] != -1)

        return memo[index];

    int robCurrent = nums[index] + helper(nums, index + 2, memo);

    int skipCurrent = helper(nums, index + 1, memo);

    int maxAmount = max(robCurrent, skipCurrent);

    memo[index] = maxAmount;

    return maxAmount;
}

int helper(vector<int> &nums, int start, int end, int sum)
// Recursion but with better space complexity
{

    if (start >= end)

        return 0;

    else if (end - start == 1)

        return sum + nums[start];

    else

        return max(sum + nums[start] + helper(nums, start + 2, end, sum), sum + helper(nums, start + 1, end, sum));
}

int robber(vector<int> &nums, int sum)
// Recursion with worse space complexity
{

    if (nums.size() == 0)
        return 0;

    else if (nums.size() == 1)

        return sum + nums[0];

    else
    {

        vector<int> nums1(nums.begin() + 1, nums.end());

        vector<int> nums2(nums.begin() + 2, nums.end());

        return max(sum + nums[0] + robber(nums2, sum), sum + robber(nums1, sum));
    }
}

int robber(vector<int> &nums)
{
    // dp table
    int n = nums.size();
    if (n == 0)
        return 0;
    else if (n == 1)
        return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> memo(n, -1);
    return helper(nums, 0, memo);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums) << endl;
    return 0;
}