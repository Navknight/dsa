#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> ans(nums.size(), -1);
    stack<int> s;

    for(int i = 0; i < 2*nums.size()-1; i++){
        int j = i%nums.size();
        while(!s.empty() && nums[s.top()] < nums[j]){
            ans[s.top()] = nums[j];
            s.pop();
        }
        s.push(j);
    }
    return ans;
}

int main()
{
    vector<int> nums = {5,4,3,2,1};
    vector<int> ans = nextGreaterElements(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}