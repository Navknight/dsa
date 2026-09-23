---
link: https://leetcode.com/problems/subtree-of-another-tree/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[BFS]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "at every node run same tree against subRoot"
time: "O(n * m)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Is `subRoot` a subtree of `root`?

# Approach
## DFS
At each node check [[Same Tree]], else recurse left and right.

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
- Time: $O(n \cdot m)$
- Space: $O(h)$

## BFS
Walk `root` with a queue, run the same check on value matches.

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
- Space: $O(n)$
