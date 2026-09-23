---
link: https://leetcode.com/problems/filter-occupied-intervals/
difficulty: Medium
topics:
  - "[[Arrays]]"
  - "[[Sorting]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sort and merge (start <= end + 1), then cut the free range with two separate ifs"
time: "O(n log n)"
space: "O(n)"
date: 2026-06-28
---

# Problem
Merge occupied intervals, then remove `[freeStart, freeEnd]` from them.

# Approach
## Sort, Merge, Cut
Sort by start. Merge when the next starts at or before `end + 1`. Cut with two separate `if`s, not `else if`, so an interval spanning the free range keeps both halves.

### Code
```cpp
vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
    sort(occupiedIntervals.begin(), occupiedIntervals.end());
    int n = occupiedIntervals.size();
    vector<vector<int>> merged;
    merged.push_back(occupiedIntervals[0]);
    for (int i = 1; i < n; i++) {
        if (occupiedIntervals[i][0] <= merged.back()[1] + 1)
            merged.back()[1] = max(merged.back()[1], occupiedIntervals[i][1]);
        else
            merged.push_back(occupiedIntervals[i]);
    }
    vector<vector<int>> result;
    for (auto& iv : merged) {
        int s = iv[0], e = iv[1];
        if (s < freeStart)
            result.push_back({s, min(e, freeStart - 1)});
        if (e > freeEnd)
            result.push_back({max(s, freeEnd + 1), e});
    }
    return result;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
