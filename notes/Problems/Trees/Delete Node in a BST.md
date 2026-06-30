---
difficulty: Medium
topics:
  - Trees
  - BST
  - DFS
source: Leetcode
star: false
link: https://leetcode.com/problems/delete-node-in-a-bst/
date: 2026-06-30
---

[[Trees]] [[DFS]]

# Problem
Given root of a BST and a key, delete the node with that key and return the root.

# Approach
## Recursive BST Delete
Use BST property to navigate to the node. Three cases on deletion:

1. **No children**: return nullptr
2. **One child**: return that child
3. **Two children**: find inorder successor (leftmost node in right subtree), copy its val to current node, then delete successor from right subtree

Return `root` at end of every branch. Lets recursion rewire parent pointers automatically without tracking parent explicitly.

Trap: `root->right = deleteNode(root->right, key)` not `return deleteNode(root->right, key)`. The latter discards current node and returns right subtree to caller.

Trap: in two-children case, `succ = succ->right` just moves local pointer. Must call `deleteNode(root->right, succ->val)` to actually remove successor from tree.

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
- Space: $O(h)$ recursion stack
