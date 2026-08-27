---
difficulty: Medium
topics:
  - Heap
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/k-closest-points-to-origin/
date: 2026-08-08
---

[[Heap]] [[Arrays]]

# Problem
Given an array of points on the 2D plane, return the `k` points closest to the origin.

# Approach
## Max Heap of size k
Keep a max heap of the `k` closest points seen so far, keyed by squared distance (no need for sqrt since we only compare). For each point, push it, and if the heap grows past `k`, pop the largest. What's left after processing all points is the `k` smallest distances.

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
</content>
</invoke>
