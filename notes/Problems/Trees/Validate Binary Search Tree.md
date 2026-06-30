---
difficulty: Medium
topics:
  - Trees
  - DFS
  - BST
source: Leetcode
star: false
link: https://leetcode.com/problems/validate-binary-search-tree/
date: 2026-06-28
---

[[Trees]] [[DFS]]

# Problem
Given root of a binary tree, determine if it is a valid BST (left subtree strictly less, right subtree strictly greater, recursively).

# Approach
## DFS with Bounds
Pass valid range (lo, hi) down. Each node must satisfy lo < val < hi strictly. Going left tightens hi to parent val; going right tightens lo to parent val.

Trap 1: checking only immediate parent-child fails. A node deep in the right subtree can still violate an ancestor's lower bound.

Trap 2: use `long` not `int` for bounds. Node vals can be INT_MIN/INT_MAX; int bounds cause false passes.

Trap 3: use `<= lo || >= hi` not `< lo || > hi`. BST has no duplicates so equal-to-bound is invalid.

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
- Space: $O(h)$: recursion stack
