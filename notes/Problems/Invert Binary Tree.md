---
link: https://leetcode.com/problems/invert-binary-tree/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "invert both subtrees, then swap them"
time: "O(n)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Mirror a binary tree.

# Approach
## Recursive Swap
Invert both children, then swap.

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
- Space: $O(h)$
