---
difficulty: Easy
topics:
  - Trees
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/invert-binary-tree/
date: 2026-06-28
---

[[Trees]] [[Recursion]]

# Problem
Given root of a binary tree, invert it (mirror) and return the root.

# Approach
## Recursive Post-order Swap

Invert both subtrees recursively, then swap them at the root. Post-order matters: invert children before touching the current node.

### Code
```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root)
        return nullptr;

    TreeNode* right = invertTree(root->left);
    TreeNode* left = invertTree(root->right);

    root->right = right;
    root->left = left;

    return root;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$ recursion stack, h = tree height
