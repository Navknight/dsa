---
difficulty: Medium
topics:
  - Backtracking
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/combination-sum-ii/
date: 2026-06-30
---

[[Backtracking]] [[Arrays]]

# Problem
Given array `candidates` (may have duplicates) and a `target`, return all unique combinations that sum to target. Each element can be used at most once.

# Approach
## Loop Backtracking with Duplicate Pruning
Sort first. At each level, iterate from `idx` forward. Skip element if it's the same value as the previous sibling at this level (`i > idx && candidates[i] == candidates[i-1]`): this prevents duplicate combinations without needing a set.

Early break when `candidates[i] + sum > target` (sorted, so all further elements also too large).

Differs from [[Combination Sum]]: include branch advances to `i+1` (no reuse), and needs the sibling-dedup check.

Trap: using `set<vector<int>>` to deduplicate causes TLE: explores all duplicate paths before discarding. Prune at source instead.

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
- Time: $O(2^n)$ worst case
- Space: $O(n)$ recursion depth
