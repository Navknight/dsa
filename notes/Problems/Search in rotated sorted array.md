---
link: https://leetcode.com/problems/search-in-rotated-sorted-array/
difficulty: Medium
topics:
  - "[[Binary Search]]"
source: Leetcode
star: true
blind75: true
mastery: red
review: 2026-11-09
insight: "one half is always sorted, check if target lies in it"
time: "O(log n)"
space: "O(1)"
date: 2026-11-08
---

# Problem
Search a target in a rotated sorted array.

# Approach
## Binary Search
One half around `m` is always sorted. If the target is in the sorted half's range, search there, else the other half. See [[Find Minimum in Rotated Sorted Array]].

- Sorted-half branch needs both ends: `nums[l] <= target < nums[m]` or `nums[m] < target <= nums[r]`
- `nums[l] <= nums[m]`, not `<`. One-element left half is still sorted
- Duplicates break the sorted-half test, see Search in Rotated Sorted Array II
- Two-pass option: find pivot (`nums[m] < nums[r] ? r = m : l = m + 1`), then binary search both runs. Same $O(\log n)$

### Mistakes
- Compared indices instead of values (`m < l`). Compare `nums[m]` with `nums[r]`
- Early exit "smaller than both ends" is wrong, the minimum can sit between `m` and `r`
- `l = m` never moves when `m == l`, infinite loop. Use `l = m + 1` or `r = m`
- Pivot loop must be `l < r`. With `l <= r` it overshoots to `pivot + 1`, and `[1]` reads out of bounds
- Checked only `nums[m]` against the target in the sorted-half branch and threw away the half with the target

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
