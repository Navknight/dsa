---
link: https://leetcode.com/problems/merge-sorted-array/
difficulty: Easy
topics:
  - "[[Arrays]]"
  - "[[Two Pointers]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "fill nums1 from the back with the larger of the two tails"
time: "O(m + n)"
space: "O(1)"
date: 2022-12-10
---

# Problem
Merge `nums2` into `nums1` in place, `nums1` has room at the end.

# Approach
## Merge from the Back
Three pointers at the tails. Write the larger one at `k`. Leftover `nums2` gets copied, leftover `nums1` is already in place.

### Code
```cpp
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = nums1.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
```

### Complexity
- Time: $O(m + n)$
- Space: $O(1)$
