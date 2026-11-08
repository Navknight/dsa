---
link: https://leetcode.com/problems/invert-binary-tree/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery: green
review: 2026-11-15
insight: "invert both subtrees, then swap them"
time: "O(n)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Mirror a binary tree.

# Approach
## Recursive Swap
Invert both children, then swap.

### Code
```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root)
        return nullptr;
    TreeNode* right = invertTree(root->left);
    TreeNode* left = invertTree(root->right);
    root->right = right;
    root->left = left;
    return root;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$

- `swap(root->left, root->right)` then recurse on both. No temporaries needed, the calls work in place
- Swap before or after the recursion, the result is the same
- Iterative: queue or stack, pop, swap children, push the ones that exist. Space O(w) for the queue, O(h) for the stack
