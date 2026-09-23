---
link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
difficulty: Easy
topics:
  - "[[Arrays]]"
  - "[[Two Pointers]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "write pointer, copy nums[i] when it differs from the last written"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Remove duplicates in place from a sorted array, return the count.

# Approach
## Overwrite
Write pointer. Copy when the value differs from the last kept. What's after `k` doesn't matter. If swaps were required, use the snowball from [[Move Zeroes]].

### Code
```cpp
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();
    int ptr = 1;
    int k = 1;
    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] != nums[i+1]){
            k++;
            nums[ptr++] = nums[i+1];
        }
    }

    return k;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
