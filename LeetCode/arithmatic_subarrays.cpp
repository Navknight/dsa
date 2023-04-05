#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> nums, int a, int b)
{
    priority_queue<int> pq;
    for(int i = a; i <= b; i++){
        pq.push(nums[i]);
    }
    if(pq.size() <= 1)
        return true;
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    int d = x-y;

    while(!pq.empty()){
        x = pq.top();
        pq.pop();
        if(y-x != d)
            return false;
        y = x;
    }
    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
    vector<bool> ans;
    for (int i = 0; i < l.size(); i++)
    {
        int a = l[i];
        int b = r[i];
        ans.push_back(check(nums, a, b));
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 6, 5, 9, 3, 7};
    vector<int> l = {0, 0, 2};
    vector<int> r = {2, 3, 5};
    vector<bool> ans = checkArithmeticSubarrays(nums, l, r);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}