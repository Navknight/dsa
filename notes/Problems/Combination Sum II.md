---
link: https://leetcode.com/problems/combination-sum-ii/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sort, loop from idx, skip i > idx && same as previous, recurse with i + 1"
time: "O(2^n)"
space: "O(n)"
date: 2026-06-30
---

# Problem
Unique combinations summing to `target`, each element used once, input has duplicates.

# Approach
## Loop Backtracking with Sibling Dedup
Sort. Loop from `idx`, skip `i > idx && candidates[i] == candidates[i-1]`. Break once `candidates[i] + sum > target`. Recurse with `i + 1`, no reuse.

Trap: `set<vector<int>>` dedup is TLE, prune at the source.

### Code
```cpp
void solve(vector<vector<int>>& ans, vector<int>& curr,
           vector<int>& candidates, int idx, int target, int sum) {
    if (sum == target) { ans.push_back(curr); return; }
    for (int i = idx; i < candidates.size(); i++) {
        if (candidates[i] + sum > target) break;
        if (i > idx && candidates[i] == candidates[i-1]) continue;
        curr.push_back(candidates[i]);
        solve(ans, curr, candidates, i+1, target, sum + candidates[i]);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    solve(ans, curr, candidates, 0, target, 0);
    return ans;
}
```

### Complexity
- Time: $O(2^n)$
- Space: $O(n)$
