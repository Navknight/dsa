---
link: https://leetcode.com/problems/contains-duplicate/
difficulty: Easy
topics:
  - "[[Arrays]]"
  - "[[Hash Maps]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "hash set, return true on first repeat"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Check if any value appears twice.

# Approach
## Hash Set
Return true on the first value already seen.

### Code
```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for(int num : nums) {
        if(seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
