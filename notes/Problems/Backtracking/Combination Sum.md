---
difficulty: Medium
topics:
  - Backtracking
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/combination-sum/
date: 2026-06-30
---

[[Backtracking]] [[Arrays]]

# Problem
Given array of distinct integers `candidates` and a `target`, return all unique combinations that sum to target. Each candidate can be used unlimited times.

# Approach
## Include/Exclude Backtracking
At each index: skip it (move to idx+1) or take it (stay at idx: allows reuse). Recurse until sum hits target or exceeds it.

Key: include branch stays at same `idx`, not `idx+1`. Moving forward would prevent reuse.

### Code
```cpp
void solve(vector<vector<int>>& ans, vector<int>& curr,
           vector<int>& candidates, int idx, int target, int sum) {
    if (sum == target) { ans.push_back(curr); return; }
    if (sum > target || idx == candidates.size()) return;

    solve(ans, curr, candidates, idx+1, target, sum);                 // exclude
    curr.push_back(candidates[idx]);
    solve(ans, curr, candidates, idx, target, sum + candidates[idx]); // include (reuse allowed)
    curr.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(ans, curr, candidates, 0, target, 0);
    return ans;
}
```

### Complexity
- Time: $O(2^{t/m})$ where $t$ = target, $m$ = smallest candidate
- Space: $O(t/m)$ recursion depth
