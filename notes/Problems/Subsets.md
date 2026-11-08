---
link: https://leetcode.com/problems/subsets/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery: yellow
review: 2026-11-11
insight: "at each index skip or take, push at the end"
time: "O(n * 2^n)"
space: "O(2^n)"
date: 2026-06-30
---

# Problem
All subsets of unique numbers.

# Approach
## Include/Exclude
Skip or take each element. Push at the end.

Trap: `{}` literal doesn't bind to `vector<int>&`, use a named variable.

- Elements are distinct and every leaf is a different take/skip path, so every leaf is a unique subset
- Duplicates in the input break that (`[1,1]`). Then sort and skip, see Subsets II
- Time is $O(n \cdot 2^n)$, each of the $2^n$ leaves copies `curr`

### Mistakes
- Used `unordered_set<vector<int>>`. No hash for vector, won't compile, and not needed
- Return type was `vector<vector<string>>` by mistake

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
- Time: $O(n \cdot 2^n)$
- Space: $O(n)$

## Iterative Cascade
Start with `{{}}`. For each number, copy every subset and append it.

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
- Time: $O(n \cdot 2^n)$
- Space: $O(2^n)$ output
