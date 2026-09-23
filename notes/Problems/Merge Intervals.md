---
link: https://leetcode.com/problems/merge-intervals/
difficulty: Medium
topics:
  - "[[Arrays]]"
  - "[[Sorting]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "sort by start, extend the current interval while the next starts before it ends"
time: "O(n log n)"
space: "O(n)"
date: 2023-03-11
---

# Problem
Merge all overlapping intervals.

# Approach
## Sort + Sweep
Sort by start. If the next starts at or before the current end, extend the end. Else push and start a new one.

### Code
```cpp
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> merged;
    if (intervals.size() == 0)
    {
        return merged;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    for (auto it : intervals)
    {
        if (it[0] <= tempInterval[1])
        {
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else
        {
            merged.push_back(tempInterval);
            tempInterval = it;
        }
    }
    merged.push_back(tempInterval);
    return merged;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
