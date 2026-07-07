---
difficulty: Medium
topics:
  - Backtracking
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/permutations/
date: 2026-06-30
---

[[Backtracking]] [[Arrays]]

# Problem
Given array of distinct integers, return all possible permutations.

# Approach
## Backtracking with Membership Check
At each level, try every number not already in `curr`. Use inner loop to check membership. Push, recurse, pop.

### Code
```cpp
void solve(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums) {
    if (curr.size() == nums.size()) { ans.push_back(curr); return; }
    for (auto n : nums) {
        bool take = true;
        for (auto c : curr) if (c == n) { take = false; break; }
        if (take) {
            curr.push_back(n);
            solve(ans, curr, nums);
            curr.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(ans, curr, nums);
    return ans;
}
```

### Complexity
- Time: $O(n! \cdot n)$
- Space: $O(n)$ recursion depth

## Backtracking with Visited Array (Cleaner)
Replace inner membership loop with boolean `used` array. O(1) lookup instead of O(n) scan per candidate.

### Code
```cpp
void solve(vector<vector<int>>& ans, vector<int>& curr,
           vector<int>& nums, vector<bool>& used) {
    if (curr.size() == nums.size()) { ans.push_back(curr); return; }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        curr.push_back(nums[i]);
        solve(ans, curr, nums, used);
        curr.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used(nums.size(), false);
    solve(ans, curr, nums, used);
    return ans;
}
```

### Complexity
- Time: $O(n! \cdot n)$
- Space: $O(n)$ recursion depth + visited array
