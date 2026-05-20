---
difficulty: Easy
topics: ["Sliding Window"]
source: Leetcode
star: true
---

[[Sliding Window]]

# Problem
Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

# Solution
Using the SNOWBALL METHOD we can move all the zeroes to the back.

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int sb = 0;
        for (int i = 0; i<n;i++){
            if(nums[i] == 0)
                sb++;
            else if(sb>0){
                nums[i-sb] = nums[i];
                nums[i] = 0;
            }
        }
    }
};
```
