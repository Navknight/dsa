---
difficulty: Easy
topics:
  - Trees
  - DFS
  - BFS
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/subtree-of-another-tree/
date: 2026-06-28
---

[[Trees]] [[DFS]] [[BFS]] [[Recursion]]

# Problem
Given roots of two trees `root` and `subRoot`, return true if `subRoot` is a subtree of `root` (some node in `root` has the same structure and values as `subRoot`).

# Approach
## DFS Recursive
At each node, check if it matches subRoot using isSame. If not, recurse left and right. Reuses [[Same Tree]] logic.

### Code
```cpp
bool isSame(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return isSame(p->left, q->left) && isSame(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;
    if (!root || !subRoot) return false;
    if (isSame(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
```

### Complexity
- Time: $O(n \cdot m)$: n nodes in root, m nodes in subRoot
- Space: $O(h)$: recursion stack

## BFS Iterative
BFS through root. On val match, run isSame check. Avoids recursion stack: better for very deep trees.

### Code
```cpp
bool isSame(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return isSame(p->left, q->left) && isSame(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;
    if (!root || !subRoot) return false;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node->val == subRoot->val && isSame(node, subRoot))
            return true;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return false;
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n)$: queue holds up to n nodes
