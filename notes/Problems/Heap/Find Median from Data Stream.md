---
difficulty: Hard
topics:
  - Heap
source: Leetcode
star: false
link: https://leetcode.com/problems/find-median-from-data-stream/
date: 2026-08-21
---

[[Heap]]

# Problem
Design a structure that supports adding numbers from a stream one at a time and finding the median of all numbers added so far.

# Approach
## Two Heaps (Max Heap + Min Heap)
Split the stream into two halves: `maxHeap` holds the smaller half (max at top), `minHeap` holds the larger half (min at top). Keep sizes within 1 of each other. If sizes are equal, median is the average of both tops; if `maxHeap` has one extra, its top is the median.

The critical step is deciding which heap a new number goes into *before* rebalancing: compare against `maxHeap.top()`. Without that comparison, a number can get stuck in the wrong heap since size-based rebalancing alone has no way to know it's misplaced.

Bugs hit along the way, worth remembering:
- Pushing every number into `maxHeap` unconditionally (no `num <= maxHeap.top()` check) breaks the "every element in maxHeap ≤ every element in minHeap" invariant. Concrete failure: insert `10, 9, 8` in that order — ends up returning `10` as the median of `{10,9,8}` instead of the correct `9`.
- Reading `minHeap.top()` while `minHeap` could still be empty (right after the very first insert, sizes are `1` and `0`) is UB, not just a wrong answer.
- Storing the running median in an `int` truncates the `.5` case before `findMedian()` ever returns it as a `double`. Needs `/2.0` and a `double`-typed running value (or just recompute from heap tops each call, as below).

### Code
```cpp
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
```

### Complexity
- Time: $O(\log n)$ per `addNum`, $O(1)$ per `findMedian`
- Space: $O(n)$ for the two heaps
