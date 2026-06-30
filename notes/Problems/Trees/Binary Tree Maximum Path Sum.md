---
difficulty: Hard
topics:
  - Trees
  - DFS
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
date: 2026-06-29
---

[[Trees]] [[DFS]] [[Recursion]]

# Problem
Given root of a binary tree, return the maximum path sum. Path can start and end at any node; does not need to pass through root.

# Approach
## DFS with Global Max
Same structure as [[Diameter of Binary Tree]]: at each node, compute best path through it using both arms, update global max, return best single arm to parent.

Key difference from diameter: values can be negative. Clamp each subtree gain to 0 before using it: never extend into a negative subtree.

At each node:
- `l = max(0, gain from left)`
- `r = max(0, gain from right)`
- Path through node: `l + root->val + r`: update global max
- Return to parent: `max(l, r) + root->val`: single arm only

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
- Space: $O(h)$ recursion stack
