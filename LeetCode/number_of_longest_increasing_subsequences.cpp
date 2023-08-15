#include <bits/stdc++.h>

using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> t(n, 0);
    vector<int> len(n, 0);
    vector<int> counter(n, 0);
    int max_length = 0, ans = 0;

    for(int i = n-1; i>=0; i--){
        int length = 1, count = 1;
        for(int j = i+1; j < n; j++){
            if(nums[j] > nums[i]){
                if(len[j] + 1 > length){
                    length = len[j] + 1;
                    count = counter[j];
                }
                else if(len[j] + 1 == length){
                    count += counter[j];
                }
            }
        }
        len[i] = length;
        counter[i] = count;

        if(length > max_length){
            ans = count;
            max_length = length;
        }
        else if(length == max_length){
            ans += count;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 2, 4};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}