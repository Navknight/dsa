#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
        int sb2 = 0;
        int sb1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                sb1++;
                nums[i] = (sb2 > 0)?2:1;
                nums[i - sb2] = 1;
            }
            else if(nums[i] == 2){
                sb2++;
            }
            else{
                nums[i] = (sb2 > 0)?2:((sb1> 0)?1:0);
                nums[i - sb2] = (sb1 > 0)?1:0;
                nums[i - sb2 - sb1] = 0;
            }
        }
    }

int main(){
    vector<int> nums = {1,0};
    sortColors(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}