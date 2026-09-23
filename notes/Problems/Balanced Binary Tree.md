---
link: https://leetcode.com/problems/balanced-binary-tree/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[Recursion]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "return -1 from height if a subtree is unbalanced, check both in one DFS"
time: "O(n)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Check if every node's subtree heights differ by at most 1.

# Approach
## Single-Pass DFS (bool ref)
Compute height bottom-up, set `bal = false` when the diff is > 1. Never set it back to true.

Brute force trap: calling `height()` and then recursing `isBalanced()` is O(n²).

### Code
```cpp
int height(TreeNode* root, bool& bal) {
    if (!root)
        return 0;
    int lHeight = height(root->left, bal);
    int rHeight = height(root->right, bal);

    if (abs(lHeight - rHeight) > 1)
        bal = false;

    return max(lHeight, rHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    if (!root)
        return true;
    bool bal = true;
    height(root, bal);
    return bal;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$

## Sentinel (-1)
Return -1 for an unbalanced subtree. Stops early.

### Code
```cpp
int dfs(TreeNode* root) {
    if (!root) return 0;
    int left = dfs(root->left);
    if (left == -1) return -1;
    int right = dfs(root->right);
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return dfs(root) != -1;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
