---
link: https://leetcode.com/problems/permutations/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "used[] array, try every unused number at each level"
time: "O(n! * n)"
space: "O(n)"
date: 2026-06-30
---

# Problem
All permutations of distinct numbers.

# Approach
## Membership Check
Try every number not in `curr`.

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
- Space: $O(n)$

## Used Array
O(1) check instead of scanning `curr`.

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
- Space: $O(n)$
