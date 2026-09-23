---
link: https://leetcode.com/problems/binary-tree-inorder-traversal/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "left, root, right"
time: "O(n)"
space: "O(n)"
date: 2023-01-04
---

# Problem
Inorder traversal.

# Approach
## Recursion
Left, root, right. Copying child vectors makes it $O(n^2)$ worst case, pass one vector by reference instead. Iterative stack version in [[Kth Smallest Element in a BST]].

### Code
```cpp
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> x;
    if (root == NULL)
    {
        return x;
    }
    vector<int> left = inorderTraversal(root->left);
    for (int i = 0; i < left.size(); i++)
    {
        x.push_back(left[i]);
    }
    x.push_back(root->val);
    vector<int> right = inorderTraversal(root->right);
    for (int i = 0; i < right.size(); i++)
    {
        x.push_back(right[i]);
    }
    return x;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
