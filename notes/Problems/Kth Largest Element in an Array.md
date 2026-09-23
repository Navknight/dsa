---
link: https://leetcode.com/problems/kth-largest-element-in-an-array/
difficulty: Medium
topics:
  - "[[Heap]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "min heap of size k, top is the kth largest"
time: "O(n log k)"
space: "O(k)"
date: 2026-08-08
---

# Problem
The `k`th largest element.

# Approach
## Min Heap of Size k
Pop the smallest when size > k.

### Code
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

### Complexity
- Time: $O(n \log k)$
- Space: $O(k)$
