---
link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
difficulty: Hard
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "clamp each arm's gain to 0, update max with l + val + r, return val + max(l, r)"
time: "O(n)"
space: "O(h)"
date: 2026-06-29
---

# Problem
Max path sum in a binary tree. Path can start and end anywhere.

# Approach
## DFS with Global Max
Same as [[Diameter of Binary Tree]] but values can be negative, so clamp each arm to 0. Path through node = `l + val + r` updates the max. Return only one arm to the parent: `max(l, r) + val`.

### Code
```cpp
int path(TreeNode* root, int& res) {
    if (!root) return 0;
    int l = path(root->left, res);
    l = l > 0 ? l : 0;
    int r = path(root->right, res);
    r = r > 0 ? r : 0;
    res = max(res, l + r + root->val);
    return max(l, r) + root->val;
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    path(root, res);
    return res;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
