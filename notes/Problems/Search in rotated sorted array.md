---
link: https://leetcode.com/problems/search-in-rotated-sorted-array/
difficulty: Medium
topics:
  - "[[Binary Search]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "one half is always sorted, check if target lies in it"
time: "O(log n)"
space: "O(1)"
date: 
---

# Problem
Search a target in a rotated sorted array.

# Approach
## Binary Search
One half around `m` is always sorted. If the target is in the sorted half's range, search there, else the other half. See [[Find Minimum in Rotated Sorted Array]].

### Code
```cpp
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1, ans = -1;

    if(nums.size() == 1)
        return (nums[0] == target) ? 0 : -1;

    while(l <= r) {
        int m = l + (r-l)/2;
        if(nums[m] == target) 
            return m;
        if(nums[l] <= nums[m]) {
            if(target < nums[l] || target > nums[m]){
                l = m+1;
            }
            else {
                r = m-1;
            }
        } else {
            if (target > nums[r] || target < nums[m])
                r = m-1;
            else 
                l = m + 1;
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(\log n)$
- Space: $O(1)$
