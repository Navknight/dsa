---
difficulty: Medium
topics:
  - Trees
  - BST
  - DFS
source: Leetcode
star: false
link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
date: 2026-06-28
---

[[Trees]] [[DFS]]

# Problem
Find the lowest common ancestor of two nodes `p` and `q` in a BST.

# Approach
## BST Property (Recursive)
LCA is either one of the nodes themselves, or the split point where p and q diverge to opposite sides. BST property gives direction for free: no need to search both subtrees.

### Code
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int curr = root->val, pval = p->val, qval = q->val;
    if (curr == pval || curr == qval) return root;
    if (curr > max(pval, qval)) return lowestCommonAncestor(root->left, p, q);
    if (curr < min(pval, qval)) return lowestCommonAncestor(root->right, p, q);
    return root;
}
```

### Complexity
- Time: $O(h)$
- Space: $O(h)$: recursion stack

## Iterative (O(1) space)
Same logic, avoids recursion stack.

### Code
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}
```

### Complexity
- Time: $O(h)$
- Space: $O(1)$
