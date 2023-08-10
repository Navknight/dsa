#include <bits/stdc++.h>

using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans (n);

    int maxi = INT32_MIN;
    for(int i = n-1; i >= 0; i--){
        int temp = 1;
        for(int j = n-1; j > i; j--){
            if(nums[i] < nums[j])
                temp = max(temp, temp+ans[j]);
        }
        ans[i] = temp;
        maxi = max(temp, maxi);
    }
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}