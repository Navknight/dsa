---
link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
difficulty: Easy
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "count drops nums[i] > nums[i+1] including the wrap, at most one allowed"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Check if the array is a sorted array rotated some number of times.

# Approach
## Brute Force
Try every rotation start and check if it's sorted.

### Code
```cpp
bool check(vector<int>& nums) {
    if(nums.size() <= 1)
        return true;
    bool ans = false;

    for(int i = 0; i < nums.size() && !ans; i++){
        for(int j = 0; j < nums.size()-1; j++){
            if(nums[(j+i)%nums.size()] <= nums[(j+1+i)%nums.size()]){
                ans = true;
            } else {
                ans = false;
                break;
            }
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(1)$

## Count Drops
A rotated sorted array has at most one place where the next element is smaller. Count drops, include last to first.

### Code
```cpp
bool check(vector<int>& nums) {
    int count = 0;

    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] > nums[i+1])
            count++;
    }

    if(nums[nums.size()-1] > nums[0])
        count++;

    return (count > 1 )? false : true;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
