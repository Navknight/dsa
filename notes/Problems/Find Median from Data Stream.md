---
link: https://leetcode.com/problems/find-median-from-data-stream/
difficulty: Hard
topics:
  - "[[Heap]]"
source: Leetcode
star: true
blind75: true
mastery: red
review: 2026-11-10
insight: "max heap for the low half, min heap for the high half. route by maxHeap.top() then rebalance"
time: "O(log n)"
space: "O(n)"
date: 2026-08-21
---

# Problem
Add numbers from a stream and return the median at any time.

# Approach
## Two Heaps
`maxHeap` = smaller half, `minHeap` = larger half. Sizes differ by at most 1, `maxHeap` gets the extra.

Route the new number by comparing with `maxHeap.top()` before rebalancing.

### Mistakes
- Pushing everything into `maxHeap` breaks the halves. `10, 9, 8` gave 10
- `minHeap.top()` on an empty heap is UB
- Storing the median as `int` drops the `.5`, use `/ 2.0`

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
- Time: $O(\log n)$ add, $O(1)$ median
- Space: $O(n)$

## Push, Pop, Rebalance
No comparison with the top. Push into `lower`, move its top to `upper`, then move one back if `upper` got bigger. Both halves stay ordered because the max of `lower` always goes across first.

### Code
```cpp
priority_queue<int> lower;
priority_queue<int, vector<int>, greater<>> upper;

void addNum(int num) {
    lower.push(num);
    upper.push(lower.top());
    lower.pop();
    if (upper.size() > lower.size()) {
        lower.push(upper.top());
        upper.pop();
    }
}

double findMedian() {
    if (lower.size() == upper.size())
        return (lower.top() + upper.top()) / 2.0;
    return lower.top();
}
```

### Complexity
- Time: $O(\log n)$ add, $O(1)$ median
- Space: $O(n)$
