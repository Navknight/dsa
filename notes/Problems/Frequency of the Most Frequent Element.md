---
link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
difficulty: Medium
topics:
  - "[[Sliding Window]]"
  - "[[Sorting]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sort, window is valid while nums[r] * len - sum <= k"
time: "O(n log n)"
space: "O(1)"
date: 
---

# Problem
Max frequency of an element after at most `k` increments.

# Approach
## Sort + Sliding Window
Sort. Raise everything in the window to `nums[r]`, cost = `nums[r] * len - sum`. Shrink while cost > `k`. Use `long long`.

### Code
```cpp
int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long sum = 0;
    int left = 0;
    int result = 0;

    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];

        while ((long long)nums[right] * (right - left + 1) - sum > k) {
            sum -= nums[left];
            ++left;
        }

        result = max(result, right - left + 1);
    }

    return result;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
