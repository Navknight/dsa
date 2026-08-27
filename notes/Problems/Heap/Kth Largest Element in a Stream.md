---
difficulty: Easy
topics: [Heap]
source: Leetcode
star: false
link: "https://leetcode.com/problems/kth-largest-element-in-a-stream/"
date: 2026-08-08
---
# Problem
Design a class to find the `k`-th largest element in a stream. `KthLargest(k, nums)` initializes the object with the integer `k` and the stream of initial numbers `nums`. `add(val)` adds `val` to the stream and returns the `k`-th largest element in the stream after insertion.
# Approach
Same min-heap-of-size-k trick as finding the k-th largest in a static array, but the heap now persists as a member variable across calls. The constructor seeds the heap by running the same push-then-pop-if-over-k logic over the initial `nums`. `add` does one push/pop-if-needed and returns the top, which is always the k-th largest since the heap never holds more than k elements.
# Code
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
# Complexity
- Time: $O(\log k)$ per `add`, $O(n \log k)$ for constructor over `n` initial elements
- Space: $O(k)$
</content>
</invoke>
