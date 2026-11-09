---
link: https://leetcode.com/problems/contains-duplicate/
difficulty: Easy
topics:
  - "[[Arrays]]"
  - "[[Hash Maps]]"
source: Leetcode
star: true
blind75: true
mastery: green
review: 2026-11-16
insight: "hash set, return true on first repeat"
time: "O(n)"
space: "O(n)"
date: 2026-11-09
---

# Problem
Check if any value appears twice.

# Approach
## Hash Set
Return true on the first value already seen. `insert(x).second` is false when `x` was already there, one lookup instead of `count` then `insert`. `reserve(n)` avoids rehashing.

### Mistakes
- Tried XOR with `0..n-1`. That works for Missing Number and Find the Duplicate, not for arbitrary values. `[1,2,3,4]` returns true
- Used `unordered_map` counts, the count is never needed

### Code
```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int x : nums)
        if (!seen.insert(x).second) return true;
    return false;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Sort
Sort, then compare neighbours. No extra space but changes the input.

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
