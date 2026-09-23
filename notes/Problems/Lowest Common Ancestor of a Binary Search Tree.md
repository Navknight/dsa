---
link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "both smaller go left, both bigger go right, else this is the split = LCA"
time: "O(h)"
space: "O(1)"
date: 2026-06-28
---

# Problem
LCA of `p` and `q` in a BST.

# Approach
## Recursive
Both smaller, go left. Both bigger, go right. Otherwise this node is where they split.

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
- Space: $O(h)$

## Iterative

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
