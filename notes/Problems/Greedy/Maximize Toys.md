---
difficulty: Easy
topics:
  - Greedy
  - Sorting
source: GFG
star: false
link: https://www.geeksforgeeks.org/problems/maximize-toys0331/1
date: 2026-08-21
---

[[Greedy]] [[Sorting]]

# Problem
Given costs of `n` toys and a budget `k`, find the maximum number of toys that can be bought without exceeding the budget.

# Approach
## Sort Ascending + Greedy Take
Buying the cheapest toys first always leaves the most budget for additional toys, so it maximizes count. Any exchange argument shows swapping a cheaper unbought toy for a costlier bought one never decreases the remaining budget, so sorting ascending and greedily taking from the front is optimal.

Sort the array, then walk left to right subtracting cost from `k` and counting purchases, stopping as soon as a toy can't be afforded (since all later toys cost at least as much).

First attempt incremented `n` (the loop bound) instead of `ans` (the return value) on each purchase — `ans` stayed 0, and since `n` grew in lockstep with `i`, the loop bound never caught up on its own, risking an out-of-bounds `arr[i]` read whenever every toy was affordable (no `break` to save it).

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
- Time: $O(n \log n)$ — dominated by the sort
- Space: $O(1)$ extra
