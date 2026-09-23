---
link: https://leetcode.com/problems/validate-binary-search-tree/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "pass (lo, hi) bounds down with long, or check inorder is strictly increasing"
time: "O(n)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Is the tree a valid BST?

# Approach
## DFS with Bounds
Pass `(lo, hi)` down. Left tightens `hi`, right tightens `lo`.

Traps:
- Checking only parent and child misses violations of higher ancestors.
- Use `long` bounds, values can be `INT_MIN` or `INT_MAX`.
- Equal to a bound is invalid.

### Code
```cpp
bool isValid(TreeNode* root, long lo, long hi) {
    if (!root) return true;
    if (root->val <= lo || root->val >= hi) return false;
    return isValid(root->left, lo, root->val) &&
           isValid(root->right, root->val, hi);
}

bool isValidBST(TreeNode* root) {
    return isValid(root, LONG_MIN, LONG_MAX);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$

## Inorder
Inorder of a BST is strictly increasing. Pass `prev` by reference so it carries across calls.

### Code
```cpp
bool inorder(TreeNode* root, TreeNode*& prev) {
    if (!root) return true;
    if (!inorder(root->left, prev)) return false;
    if (prev && root->val <= prev->val) return false;
    prev = root;
    return inorder(root->right, prev);
}
bool isValidBST(TreeNode* root) {
    TreeNode* prev = nullptr;
    return inorder(root, prev);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
