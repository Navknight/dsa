---
difficulty: Easy
topics:
  - Trees
  - DFS
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/same-tree/
date: 2026-06-28
---

[[Trees]] [[DFS]] [[Recursion]]

# Problem
Given roots of two binary trees, check if they are structurally identical with the same node values.

# Approach
## Recursive DFS
Three base cases handle all null combos. Short-circuit on val mismatch before recursing into subtrees.

### Code
```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val != q->val)
        return false;
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$: recursion stack
