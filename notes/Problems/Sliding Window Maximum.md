---
link: https://leetcode.com/problems/sliding-window-maximum/
difficulty: Hard
topics:
  - "[[Sliding Window]]"
  - "[[Deque]]"
  - "[[Monotonic Stack]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "deque of indices with decreasing values, front is the max, pop it when it leaves the window"
time: "O(n)"
space: "O(n)"
date: 2026-05-22
---

# Problem
Max of every window of size `k`.

# Approach
## Frequency Map
Track counts in the window. When the max leaves, rescan the window.

### Code
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> mp;

    int l = 0, r = 0, maxr = INT_MIN, n = nums.size();
    while (r < n) {
        mp[nums[r]]++;
        maxr = max(maxr, nums[r]);
        if (r - l + 1 == k) {
            ans.push_back(maxr);
        } else if (r - l + 1 > k) {
            mp[nums[l++]]--;
            if (mp[maxr] == 0) {
                maxr = INT_MIN;
                for (int i = l; i <= r; i++) {
                    maxr = max(maxr, nums[i]);
                }
            }
            ans.push_back(maxr);
        }
        r++;
    }
    return ans;
}
```

### Complexity
- Time: $O(nk)$
- Space: $O(k)$

## Monotonic Deque
Deque of indices, values decreasing. A new element pops every smaller one from the back, it outlives them. Pop the front when it leaves the window.

### Code
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;

    int n = nums.size();

    for (int r = 0; r < n; r++) {
        if (!dq.empty() && dq.front() < r - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[r]) {
            dq.pop_back();
        }

        dq.push_back(r);

        if (r >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(k)$
