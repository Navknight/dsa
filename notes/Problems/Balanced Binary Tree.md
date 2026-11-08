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
mastery: yellow
review: 2026-11-11
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

- `height(root) != -1` is the whole answer

### Mistakes
- First try was top-down, `height()` at every node. O(n²) on a skewed tree
- Forgot to return the child's -1 up. abs(-1 - 0) is 1, so it looked balanced
- Last line called `height()` again instead of using `l` and `r`. 3 calls per child, exponential on a deep chain
- `isBalanced` checked `height(child) > 0`. Null child is 0, so `[1]` came out unbalanced

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
