---
difficulty: Medium
topics:
  - Backtracking
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/subsets/
date: 2026-06-30
---

[[Backtracking]] [[Arrays]]

# Problem
Given integer array `nums` of unique elements, return all possible subsets (power set).

# Approach
## Include/Exclude Backtracking
At each index, two choices: skip element or include it. Recurse both paths. Base case: index reaches end, push current subset.

Pass `curr` by reference with pop_back to undo after include branch.

Trap: passing `{}` literal as `vector<int>&` won't compile: declare named variable first.

### Code
```cpp
void solve(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int idx) {
    if (idx == nums.size()) { ans.push_back(curr); return; }
    solve(ans, curr, nums, idx+1);          // exclude
    curr.push_back(nums[idx]);
    solve(ans, curr, nums, idx+1);          // include
    curr.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(ans, curr, nums, 0);
    return ans;
}
```

### Complexity
- Time: $O(2^n)$
- Space: $O(n)$ recursion stack

## Iterative (Cascade)
Start with `{{}}`. For each number, duplicate all existing subsets and append the number to each copy. No recursion, no backtracking.

### Code
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans = {{}};
    for (int n : nums) {
        int sz = ans.size();
        for (int i = 0; i < sz; i++) {
            auto sub = ans[i];
            sub.push_back(n);
            ans.push_back(sub);
        }
    }
    return ans;
}
```

### Complexity
- Time: $O(2^n)$
- Space: $O(2^n)$ output only, no recursion stack
