---
link: https://leetcode.com/problems/sort-colors/
difficulty: Medium
topics:
  - "[[Arrays]]"
  - "[[Two Pointers]]"
  - "[[Sorting]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "Dutch flag: low, mid, high pointers, swap 0s to low and 2s to high"
time: "O(n)"
space: "O(1)"
date: 2023-03-11
---

# Problem
Sort an array of 0s, 1s and 2s in place, one pass.

# Approach
## Two Snowballs
`sb2` = 2s seen, `sb1` = 1s seen. Each new value gets written back past the snowballs, like [[Move Zeroes]]. The usual way is Dutch flag with `low`, `mid`, `high`.

### Code
```cpp
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
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
