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
mastery: red
review: 2026-11-11
insight: "two pointers from both ends, move left if sum is small, right if big"
time: "O(n)"
space: "O(1)"
date: 2026-05-18
---

# Problem
Two Sum on a sorted array, O(1) space.

# Approach
## Binary Search
Fix `l`, binary search `target - numbers[l]` on the right. Search only `i + 1..n - 1`, then `m > i` always and the answer is `{i + 1, m + 1}`.

### Mistakes
- Compared `numbers[m]` to `target`, not to `req = target - numbers[i]`
- `if (m == i) continue;` inside the loop never moves `l` or `r`, infinite loop (TLE). Start `l` at `i + 1` instead
- `while (l < r)` skips the last candidate, needs `l <= r`
- Went for binary search per element, two pointers was the intended pattern

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

- Moving `r` is safe when the sum is too big: `numbers[r]` can't pair with `l` or anything right of it, all at least as large
- Loop on `l < r`. Don't compute the sum three times. A `!= target` loop condition makes an inner `else` return dead code

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
