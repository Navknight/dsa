---
link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
difficulty: Medium
topics:
  - "[[Arrays]]"
  - "[[Binary Search]]"
  - "[[Two Pointers]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "two pointers from both ends, move left if sum is small, right if big"
time: "O(n)"
space: "O(1)"
date: 2026-05-18
---

# Problem
Two Sum on a sorted array, O(1) space.

# Approach
## Binary Search
Fix `l`, binary search `target - numbers[l]` on the right.

### Code
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    for (int l = 0; l < n - 1; l++) {
        int t = target - numbers[l];
        if (numbers[l] > t)
            break;

        int r = l + 1, e = n - 1;
        while (r <= e) {
            int m = r + (e - r) / 2;
            if (numbers[m] == t)
                return {l + 1, m + 1};
            else if (numbers[m] < t)
                r = m + 1;
            else
                e = m - 1;
        }
    }
    return {};
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$

## Two Pointers
Start at both ends. Sum too small, move left. Too big, move right.

### Code
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int l = 0, r = n - 1;

    while (l <= r) {
        if (numbers[l] + numbers[r] == target)
            return {l + 1, r + 1};
        else if (numbers[l] + numbers[r] > target)
            r--;
        else
            l++;
    }

    return {};
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
