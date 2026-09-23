---
link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
difficulty: Easy
topics:
  - "[[Heap]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "keep a min heap of size k as a member, top is the answer"
time: "O(log k)"
space: "O(k)"
date: 2026-08-08
---

# Problem
Return the `k`th largest after each `add`.

# Approach
## Min Heap of Size k
Same as [[Kth Largest Element in an Array]] with the heap kept across calls.

### Code
```cpp
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto i : nums) {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > K)
            pq.pop();
        return pq.top();
    }
};
```

### Complexity
- Time: $O(\log k)$ per add
- Space: $O(k)$
