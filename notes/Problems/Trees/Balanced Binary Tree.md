---
difficulty: Easy
topics:
  - Trees
  - DFS
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/balanced-binary-tree/
date: 2026-06-28
---

[[Trees]] [[DFS]] [[Recursion]]

# Problem
Given a binary tree, determine if it is height-balanced: every node's left and right subtree heights differ by at most 1.

# Approach
## Single-Pass DFS (bool ref)
Compute height bottom-up. Pass a `bool& bal` ref: only ever flip to `false`, never back to `true`. If any node is unbalanced, `bal` stays false all the way up.

Brute force mistake: calling `height()` separately then recursing `isBalanced()` = O(n²). Fix: combine both in one DFS.

Key invariant: `bal` starts `true`, only `> 1` diff sets it `false`. Never reset to `true` at a balanced node: that would clobber earlier `false`.

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
- Space: $O(h)$: recursion stack

## Sentinel Value (-1)
Return -1 if subtree unbalanced, else height. Short-circuits early: stops recursing as soon as imbalance found.

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
