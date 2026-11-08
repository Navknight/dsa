---
link: https://leetcode.com/problems/meeting-rooms/
difficulty: Easy
topics:
  - "[[Sorting]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery: yellow
review: 2026-11-11
insight: "sort by start, then any overlap shows up between neighbours: end > next start"
time: "O(n log n)"
space: "O(1)"
date: 2026-11-08
---

# Problem
Can one person attend every meeting, i.e. no two intervals overlap.

# Approach
## Sort by start, compare neighbours
After sorting by start, if any two meetings overlap then some adjacent pair does. One pass over the neighbours.

- Ending exactly when the next starts is fine, so the check is `end > next.start`
- Sorts the caller's input in place

### Mistakes
- Loop bound `intervals.size() - 1` wraps on an empty list (unsigned). Use `int n` or `i + 1 < size()`

### Code
```cpp
bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const Interval& a, const Interval& b) { return a.start < b.start; });
    int n = intervals.size();
    for (int i = 0; i < n - 1; i++) {
        if (intervals[i].end > intervals[i + 1].start) return false;
    }
    return true;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
