---
link: https://leetcode.com/problems/find-the-duplicate-number/
difficulty: Medium
topics:
  - "[[Linked Lists]]"
  - "[[Arrays]]"
  - "[[Bit Manipulation]]"
  - "[[Binary Search]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "value as pointer to index makes a cycle, Floyd's entry point is the duplicate"
time: "O(n)"
space: "O(1)"
date: 2026-06-27
---

# Problem
`n+1` values in `[1, n]`, one repeats. Find it without modifying the array, O(1) space.

# Approach
## Floyd's Cycle Detection
Treat each value as a pointer to an index. Pigeonhole makes a cycle, its entry is the duplicate. Phase 1: slow and fast meet. Phase 2: one pointer from 0, one from the meeting point, both 1 step.

### Code
```cpp
int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    int slow2 = 0;
    while (slow != slow2) {
        slow  = nums[slow];
        slow2 = nums[slow2];
    }
    return slow;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

## Bit Counting
Per bit, count set bits in `1..n` vs in `nums`. More in `nums` means the duplicate has that bit.

### Code
```cpp
int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1, duplicate = 0;
    for (int bit = 0; bit < 32; bit++) {
        int base = 0, actual = 0;
        for (int i = 1; i <= n; i++) base   += (i >> bit) & 1;
        for (int x : nums)          actual  += (x >> bit) & 1;
        if (actual > base) duplicate |= (1 << bit);
    }
    return duplicate;
}
```

### Complexity
- Time: $O(32n)$
- Space: $O(1)$

## Binary Search on Value
Count elements `<= mid`. More than `mid` means the duplicate is in `[1, mid]`.

### Code
```cpp
int findDuplicate(vector<int>& nums) {
    int lo = 1, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int count = 0;
        for (int x : nums) count += (x <= mid);
        if (count > mid) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
