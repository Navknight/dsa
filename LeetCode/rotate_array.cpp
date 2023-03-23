#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    while (k--)
    {
        int key = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            nums[i + 1] = nums[i];
        }
        nums[0] = key;
    }
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}