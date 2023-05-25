#include <bits/stdc++.h>

using namespace std;

int deleteAndEarn(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    unordered_map<int, int> m;
    vector<int> uni;
    int prev = -1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
        if (nums[i] == prev)
            continue;
        else
        {
            uni.push_back(nums[i]);
            prev = nums[i];
        }
    }

    int t1 = 0, t2 = 0;

    for (int i = 0; i < uni.size(); i++)
    {
        if (i > 0 && uni[i] - uni[i - 1] == 1)
        {
            int temp = t2;
            t2 = max(t2, t1 + uni[i] * m[uni[i]]);
            t1 = temp;
        }
        else
        {
            int temp = t2;
            t2 = t2 + uni[i] * m[uni[i]];
            t1 = max(temp, t1);
        }
    }

    return max(t1, t2);
}

int main()
{
    vector<int> nums = {8, 10, 4, 9, 1, 3, 5, 9, 4, 10};
    cout << deleteAndEarn(nums) << endl;
    return 0;
}