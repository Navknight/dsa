---
link: https://www.geeksforgeeks.org/problems/maximize-toys0331/1
difficulty: Easy
topics:
  - "[[Greedy]]"
  - "[[Sorting]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "sort ascending, buy cheapest first until the budget runs out"
time: "O(n log n)"
space: "O(1)"
date: 2026-08-21
---

# Problem
Max toys you can buy with budget `k`.

# Approach
## Sort + Greedy
Cheapest first always leaves the most budget. Stop at the first toy you can't afford.

Mistake I made: incremented `n` instead of `ans`.

### Code
```cpp
class Solution {
public:
    int toyCount(vector<int> arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = 0;
        for (int i = 0; i < n && k > 0; i++) {
            if (arr[i] <= k) {
                k -= arr[i];
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(1)$
