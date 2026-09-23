---
link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "1 + max(depth(left), depth(right))"
time: "O(n)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Max depth of a binary tree.

# Approach
## DFS
`1 + max(left, right)`.

### Code
```cpp
int maxDepth(TreeNode* root) {
    if (!root)
        return 0;

    return max(maxDepth(root->right), maxDepth(root->left)) + 1;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
