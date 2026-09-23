---
link: https://leetcode.com/problems/subsets-ii/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "sort, push curr at every call, skip i > idx && nums[i] == nums[i-1]"
time: "O(n * 2^n)"
space: "O(n)"
date: 2026-06-30
---

# Problem
All subsets without duplicates, input has duplicates.

# Approach
## Loop Backtracking with Sibling Dedup
Like [[Combination Sum II]]. Sort. Push `curr` on every call. Skip `i > idx && nums[i] == nums[i-1]`.

Trap: a second recursive call after `pop_back` inside the loop makes duplicates. The loop already moves on.

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
- Time: $O(n \cdot 2^n)$
- Space: $O(n)$

## Iterative Cascade
Sort. For a duplicate, extend only the subsets added in the last round.

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
- Time: $O(n \cdot 2^n)$
- Space: $O(2^n)$ output
