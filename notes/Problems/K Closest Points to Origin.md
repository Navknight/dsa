---
link: https://leetcode.com/problems/k-closest-points-to-origin/
difficulty: Medium
topics:
  - "[[Heap]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "max heap of size k keyed by squared distance"
time: "O(n log k)"
space: "O(k)"
date: 2026-08-08
---

# Problem
The `k` points closest to the origin.

# Approach
## Max Heap of Size k
Push `x² + y²`, pop when size > k. No sqrt needed.

### Code
```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto p : points) {
            pq.push({p[0] * p[0] + p[1] * p[1], {p[0], p[1]}});
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (pq.size()) {
            auto p = pq.top();
            pq.pop();

            ans.push_back({p.second.first, p.second.second});
        }

        return ans;
    }
};
```

### Complexity
- Time: $O(n \log k)$
- Space: $O(k)$
