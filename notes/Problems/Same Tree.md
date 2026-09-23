---
link: https://leetcode.com/problems/same-tree/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "both null true, one null false, compare val then recurse"
time: "O(n)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Are two trees identical?

# Approach
## DFS
Both null: true. One null or different values: false. Else recurse on both sides.

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
- Space: $O(h)$
