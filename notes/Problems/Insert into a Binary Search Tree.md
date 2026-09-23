---
link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[Recursion]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "walk down by BST order, insert at the null spot, return root to rewire"
time: "O(h)"
space: "O(h)"
date: 2023-01-12
---

# Problem
Insert a value into a BST.

# Approach
## Recursion
Go left or right by value, create the node at the first null. Assign the returned subtree back to the parent.

### Code
```cpp
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return root;
    }
    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}
```

### Complexity
- Time: $O(h)$
- Space: $O(h)$
