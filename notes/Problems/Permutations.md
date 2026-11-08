---
link: https://leetcode.com/problems/permutations/
difficulty: Medium
topics:
  - "[[Backtracking]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery: yellow
review: 2026-11-11
insight: "used[] array, or swap nums[idx] with each nums[j >= idx], swap back"
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

## Swap in Place
No `used`, no `curr`. Prefix `nums[0..idx-1]` is the permutation so far, the suffix is what's left. At `idx`, swap each `nums[j]` (`j >= idx`) into place, recurse, swap back. At `idx == n` the array is one answer.

- `j` starts at `idx`, not `idx + 1`. `j = idx` is the "keep it" choice
- Swap back after the recursive call, or the next `j` sees a scrambled array
- Order is not lexicographic (`123, 132, 213, 231, 321, 312`), fine on LC
- Duplicates repeat permutations, that is Permutations II (sort + skip, or a seen set per level)

### Mistakes
- Started `j` at `idx + 1`, which returned an empty list for every input

### Code
```cpp
void solve(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    if (idx == nums.size()) { ans.push_back(nums); return; }
    for (int j = idx; j < nums.size(); j++) {
        swap(nums[idx], nums[j]);
        solve(nums, idx + 1, ans);
        swap(nums[idx], nums[j]);
    }
}
```

### Complexity
- Time: $O(n \cdot n!)$, $n!$ leaves each copy $n$ elements
- Space: $O(n)$ recursion, plus output

## next_permutation
Sort, then loop. Iterative, lexicographic order. Same total cost.

### Code
```cpp
vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    do { ans.push_back(nums); } while (next_permutation(nums.begin(), nums.end()));
    return ans;
}
```

## Heap's Algorithm
One swap between consecutive permutations. The copy into `ans` still costs $O(n)$, so the total does not change. Useful when you process each permutation in place.

### Code
```cpp
void heaps(vector<int>& a, int k, vector<vector<int>>& ans) {
    if (k == 1) { ans.push_back(a); return; }
    heaps(a, k - 1, ans);
    for (int i = 0; i < k - 1; i++) {
        if (k % 2 == 0) swap(a[i], a[k - 1]);
        else swap(a[0], a[k - 1]);
        heaps(a, k - 1, ans);
    }
}
// heaps(nums, nums.size(), ans)
```
