---
link: https://leetcode.com/problems/symmetric-tree/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "mirror check: t1->left vs t2->right and t1->right vs t2->left"
time: "O(n)"
space: "O(h)"
date: 2023-01-12
---

# Problem
Is the tree a mirror of itself?

# Approach
## Mirror DFS
Like [[Same Tree]] but compare crossed children.

### Code
```cpp
bool isMirror(TreeNode *t1, TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return isMirror(root->left, root->right);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
