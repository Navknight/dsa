---
link: https://leetcode.com/problems/smallest-range-ii/
difficulty: Medium
topics:
  - "[[Sorting]]"
  - "[[Greedy]]"
  - "[[Math]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sort, split at i: first part +k, rest -k. max = max(a[n-1]-k, a[i]+k), min = min(a[0]+k, a[i+1]-k)"
time: "O(n log n)"
space: "O(1)"
date: 
---

# Problem
Add `+k` or `-k` to each element, minimize max - min.

# Approach
## Sort + Split
After sorting, the best is some prefix `+k` and the suffix `-k`. For each split `i`: max = `max(a[n-1]-k, a[i]+k)`, min = `min(a[0]+k, a[i+1]-k)`.

### Code
```cpp
int smallestRangeII(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int ans = nums.back() - nums[0];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int a = nums[i];
        int b = nums[i + 1];
        int high = max(nums.back() - k, a + k);
        int low = min(nums[0] + k, b - k);
        ans = min(ans, high - low);
    }
    return ans;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
