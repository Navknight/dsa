---
link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "return the node if it's p or q, if both sides return non-null this is the LCA"
time: "O(n)"
space: "O(h)"
date: 2023-01-31
---

# Problem
LCA of `p` and `q` in a binary tree (not a BST).

# Approach
## DFS
Return `root` if it's null, `p` or `q`. Recurse both sides. Both non-null means `p` and `q` split here. Else pass up whichever side found something. BST version: [[Lowest Common Ancestor of a Binary Search Tree]].

### Code
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL || p == root || q == root) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    return (right)?right:left;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
