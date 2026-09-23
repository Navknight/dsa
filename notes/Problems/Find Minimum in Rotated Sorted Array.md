---
link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
difficulty: Medium
topics:
  - "[[Binary Search]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "compare mid with right end, min is in the unsorted half"
time: "O(log n)"
space: "O(1)"
date: 
---

# Problem
Min of a rotated sorted array.

# Approach
## Binary Search
If `nums[l] < nums[r]` the range is sorted, `nums[l]` is a candidate. Else go to the half with the dip: `nums[m] >= nums[l]` means the left half is sorted, go right.

### Code
```cpp
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, ans = nums[0];

    while(l <= r) {
        if(nums[l] < nums[r])
            ans = min(ans, nums[l]);

        int m = l + (r-l)/2;
        ans = min(ans, nums[m]);

        if(nums[m] >= nums[l])
            l = m + 1;
        else 
            r = m - 1;
    }

    return ans;
}
```

### Complexity
- Time: $O(\log n)$
- Space: $O(1)$
