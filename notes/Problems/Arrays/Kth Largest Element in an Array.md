---
difficulty: Medium
topics: [Heap, Arrays]
source: Leetcode
star: false
link: "https://leetcode.com/problems/kth-largest-element-in-an-array/"
date: 2026-08-08
---
# Problem
Given an integer array `nums` and an integer `k`, return the `k`-th largest element in the array.
# Approach
Keep a min-heap capped at size `k`. Push every element, and pop the smallest whenever the heap exceeds size `k`. After processing all elements, the smallest of the top-`k` largest sits at the top, which is exactly the `k`-th largest.
# Code
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto i : nums) {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};
```
# Complexity
- Time: $O(n \log k)$
- Space: $O(k)$
</content>
</invoke>
