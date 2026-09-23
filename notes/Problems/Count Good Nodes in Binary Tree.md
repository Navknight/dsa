---
link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[Recursion]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "pass the path max down by value, count nodes with val >= max"
time: "O(n)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Count nodes with no greater value on the path from the root.

# Approach
## DFS with Path Max
Pass the max down by value. Good if `val >= max`.

Trap: passing `m` by reference leaks the left branch's max into the right.

### Code
```cpp
int solve(TreeNode* root, int m) {
    if (!root) return 0;
    m = max(root->val, m);
    int l = solve(root->left, m);
    int r = solve(root->right, m);
    return (m <= root->val) ? l + r + 1 : l + r;
}

int goodNodes(TreeNode* root) {
    return solve(root, INT_MIN);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
