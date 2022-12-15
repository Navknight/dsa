#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    for (int i = 0; i < nums.size();)
    {
        if (nums[i] >= 1 && nums[i] <= nums.size())
        {
            int cor_pos = nums[i] - 1;
            if (nums[i] != nums[cor_pos])
            {
                swap(nums[i], nums[cor_pos]);
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return nums.size() + 1;
}

int main()
{
    vector<int> nums = {3, 4, -1, 1};
    cout << firstMissingPositive(nums) << endl;
    return 0;
}