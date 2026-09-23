---
link: https://leetcode.com/problems/combination-sum/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "take and stay at idx (reuse) or skip to idx + 1"
time: "O(2^(t/m))"
space: "O(t/m)"
date: 2026-06-30
---

# Problem
Combinations of distinct candidates summing to `target`, unlimited reuse.

# Approach
## Include/Exclude
Skip moves to `idx + 1`. Take stays at `idx`, that's what allows reuse.

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
- Time: $O(2^{t/m})$, t = target, m = smallest candidate
- Space: $O(t/m)$
