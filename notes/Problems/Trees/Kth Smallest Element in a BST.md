---
difficulty: Medium
topics:
  - Trees
  - DFS
  - BST
source: Leetcode
star: false
link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
date: 2026-06-29
---

[[Trees]] [[DFS]]

# Problem
Given root of a BST and integer k, return the kth smallest element.

# Approach
## Inorder DFS (Recursive)
Inorder traversal of a BST yields values in sorted ascending order. Decrement k at each visited node; when k hits 0, that node is the answer.

Pass k by reference so all recursive calls share the same counter. Return -1 as sentinel for "not found yet"; propagate the real answer up when found.

### Code
```cpp
int inorder(TreeNode* root, int& k) {
    if (!root) return -1;
    int l = inorder(root->left, k);
    if (l > -1) return l;
    if (--k == 0) return root->val;
    int r = inorder(root->right, k);
    if (r > -1) return r;
    return -1;
}

int kthSmallest(TreeNode* root, int k) {
    return inorder(root, k);
}
```

### Complexity
- Time: $O(H + k)$
- Space: $O(H)$ recursion stack

## Inorder Iterative (Cleaner)
Same logic with explicit stack. No sentinel value, no reference param, no helper function.

### Code
```cpp
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    while (root || !st.empty()) {
        while (root) { st.push(root); root = root->left; }
        root = st.top(); st.pop();
        if (--k == 0) return root->val;
        root = root->right;
    }
    return -1;
}
```

### Complexity
- Time: $O(H + k)$
- Space: $O(H)$ stack

## Follow-up: Frequent Queries on a Mutable BST
Augment each node with left-subtree count. Each query becomes $O(H)$ instead of $O(H + k)$. Each insert/delete updates ancestor counts in $O(H)$.
