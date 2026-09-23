---
link: https://leetcode.com/problems/move-zeroes/
difficulty: Easy
topics:
  - "[[Two Pointers]]"
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "write pointer for non-zeros, fill the rest with 0"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Move all 0s to the end in place, keep the order of the rest.

# Approach
## Snowball
`sb` = zeros seen so far. Each non-zero moves back by `sb` and leaves a 0 behind.

### Code
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

### Complexity
- Time: $O(n)$
- Space: $O(1)$
