<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

int helper(vector<int>& nums, int index, vector<int>& memo) {
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

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n, -1);
    return helper(nums, 0, memo);
}

int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums) << endl;
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

int rob(vector<int> &nums)
{

}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums) << endl;
    return 0;
>>>>>>> 3a3501ec2f6751e05c87576db001a34de62bd84a
}