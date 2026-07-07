---
difficulty: Medium
topics:
  - Backtracking
  - Arrays
source: Leetcode
star: true
link: https://leetcode.com/problems/subsets-ii/
date: 2026-06-30
---

[[Backtracking]] [[Arrays]]

# Problem
Given integer array `nums` that may contain duplicates, return all possible subsets with no duplicate subsets.

# Approach
## Loop Backtracking with Sibling Dedup
Same pattern as [[Combination Sum II]]. Sort first. Push `curr` at every call (not just leaf) since every state is a valid subset. Loop from `idx`, skip duplicate siblings with `i > idx && nums[i] == nums[i-1]`.

Trap: mixing for-loop with a second recursive call after pop_back causes duplicates. The loop already advances to next element naturally; no second call needed.

### Code
```cpp
void solve(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int idx) {
    ans.push_back(curr);
    for (int i = idx; i < nums.size(); i++) {
        if (i > idx && nums[i] == nums[i-1]) continue;
        curr.push_back(nums[i]);
        solve(ans, curr, nums, i+1);
        curr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> curr;
    solve(ans, curr, nums, 0);
    return ans;
}
```

### Complexity
- Time: $O(2^n)$
- Space: $O(n)$ recursion depth

## Iterative Cascade
Sort first. For each new number, duplicate subsets from last round only if it's a duplicate of the previous element; otherwise duplicate all. Track `start` index of last round's additions.

### Code
```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans = {{}};
    int start = 0;
    for (int i = 0; i < nums.size(); i++) {
        start = (i > 0 && nums[i] == nums[i-1]) ? start : 0;
        int sz = ans.size();
        for (int j = start; j < sz; j++) {
            auto v = ans[j];
            v.push_back(nums[i]);
            ans.push_back(v);
        }
        start = sz;
    }
    return ans;
}
```

### Complexity
- Time: $O(2^n)$
- Space: $O(2^n)$ output only
