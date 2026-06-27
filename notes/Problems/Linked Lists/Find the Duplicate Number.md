---
difficulty: Medium
topics:
  - Linked Lists
  - Arrays
  - Bit Manipulation
  - Binary Search
source: Leetcode
star: true
link: https://leetcode.com/problems/find-the-duplicate-number/
date: 2026-06-27
---

[[Linked Lists]] [[Arrays]] [[Bit Manipulation]] [[Binary Search]]

# Problem
Array of `n+1` integers where each integer is in `[1, n]`. Exactly one number is repeated. Find it without modifying the array and using O(1) extra space.

# Approach
## Floyd's Cycle Detection (Optimal)
Array has `n+1` elements, values in `[1..n]`. Treat each value as a pointer to an index. Since two indices must point to the same value (pigeonhole), following `i → nums[i]` creates a cycle. The cycle entry = duplicate.

Phase 1: find intersection (slow=1 step, fast=2 steps from index 0).
Phase 2: find cycle entry (one pointer from 0, one from intersection, both 1 step).

```
index:  0  1  2  3  4
nums:  [3, 1, 3, 4, 2]
path: 0→3→4→2→3→4→... (cycle entry at 3)
```

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

## Bit Manipulation
For each bit position, count how many numbers in `[1..n]` have that bit set (`base`) vs how many in `nums` have it set (`actual`). If `actual > base`, the duplicate has that bit set.

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
- Time: $O(32n) = O(n)$
- Space: $O(1)$

## Binary Search on Answer
Binary search over value range `[1..n]`. For mid, count elements in `nums` that are `<= mid`. If count `> mid`, duplicate is in `[1..mid]`; else in `[mid+1..n]`.

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
- Time: $O(n log n)$
- Space: $O(1)$