---
link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "inorder of a BST is sorted, stop at the kth visited node"
time: "O(h + k)"
space: "O(h)"
date: 2026-06-29
---

# Problem
`k`th smallest value in a BST.

# Approach
## Recursive Inorder
Decrement `k` (by ref) on each visit, return the node when it hits 0. -1 = not found yet.

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
- Time: $O(h + k)$
- Space: $O(h)$

## Iterative Inorder
Explicit stack, no sentinel or ref.

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
- Time: $O(h + k)$
- Space: $O(h)$

Follow-up, frequent queries on a changing BST: store left subtree size per node, each query is $O(h)$.
