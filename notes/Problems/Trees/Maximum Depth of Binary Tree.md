---
difficulty: Easy
topics:
  - Trees
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
date: 2026-06-28
---

[[Trees]] [[Recursion]]

# Problem
Given root of a binary tree, return its maximum depth.

# Approach
## Recursive DFS

Current node counts as 1 + the max depth between its left and right subtrees.

# Code
```cpp
int maxDepth(TreeNode* root) {
    if (!root)
        return 0;

    return max(maxDepth(root->right), maxDepth(root->left)) + 1;
}
```

# Complexity
- Time: $O(n)$
- Space: $O(h)$ recursion stack, h = tree height
