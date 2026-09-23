---
link: https://leetcode.com/problems/delete-node-in-a-bst/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "two children: copy the inorder successor's val, then delete it from the right subtree"
time: "O(h)"
space: "O(h)"
date: 2026-06-30
---

# Problem
Delete `key` from a BST and return the root.

# Approach
## Recursive Delete
Navigate by BST property. On the node:
1. No children: return nullptr
2. One child: return it
3. Two children: copy the inorder successor's val, delete the successor from the right subtree

Return `root` from every branch so parents rewire themselves.

Traps:
- `root->right = deleteNode(...)`, not `return deleteNode(...)`.
- Moving `succ` doesn't delete it, call `deleteNode(root->right, succ->val)`.

### Code
```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (root->val == key) {
        if (!root->left && !root->right) return nullptr;
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* succ = root->right;
        while (succ->left) succ = succ->left;
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        root->left = deleteNode(root->left, key);
    }
    return root;
}
```

### Complexity
- Time: $O(h)$
- Space: $O(h)$
