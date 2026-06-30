---
difficulty: Medium
topics:
  - Arrays
  - Sorting
source: Leetcode
star: false
link: https://leetcode.com/contest/weekly-contest-508/problems/filter-occupied-intervals/
date: 2026-06-28
---

[[Arrays]] [[Sorting]]

# Problem
Given occupied intervals (may overlap), merge them, then remove all points in `[freeStart, freeEnd]`. Return remaining occupied intervals sorted.

# Approach
## Sort, Merge, Cut

Two phases. Sort by start. Merge touching/overlapping intervals: next starts within `curr.end + 1`.

Cut the free interval with two independent `if`s (not `else-if`: spanning case needs both):
- If interval starts left of free zone: keep left part `[s, freeStart-1]`
- If interval ends right of free zone: keep right part `[freeEnd+1, e]`

Two separate `if`s handles the spanning case (interval contains entire free interval): outputs both halves.

# Code
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

# Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
