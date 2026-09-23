---
link: https://leetcode.com/problems/median-of-two-sorted-arrays/
difficulty: Hard
topics:
  - "[[Arrays]]"
  - "[[Binary Search]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "binary search the partition of the smaller array so left halves hold (m+n+1)/2 elements"
time: "O(m + n)"
space: "O(m + n)"
date: 2023-01-31
---

# Problem
Median of two sorted arrays.

# Approach
## Merge Until the Middle
Merge like merge sort until past the midpoint, read the middle one or two.

### Code
```cpp
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int t = nums1.size() + nums2.size();
    int h = t / 2;
    vector<int> a;
    int i = 0;
    int j = 0;
    while (t-- >= h)
    {
        if (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                a.push_back(nums1[i]);
                i++;
            }
            else
            {
                a.push_back(nums2[j]);
                j++;
            }
        }
        else if (i < nums1.size())
        {
            a.push_back(nums1[i]);
            i++;
        }
        else if (j < nums2.size())
        {
            a.push_back(nums2[j]);
            j++;
        }
    }
    int n = a.size();
    // for(int i = 0; i < n; i++)
    //     cout<<a[i]<<" ";
    if (n >= 2)
        return ((nums1.size() + nums2.size()) % 2 == 0) ? (float)(a[n - 1] + a[n - 2]) / 2.0 : (float)a[n - 2];
    else
        return a[0];
}
```

### Complexity
- Time: $O(m + n)$
- Space: $O(m + n)$

## Binary Search on the Partition
The intended solution. Cut the smaller array at `i` and the other at `(m+n+1)/2 - i`. Valid when `A[i-1] <= B[j]` and `B[j-1] <= A[i]`. $O(\log \min(m, n))$.
