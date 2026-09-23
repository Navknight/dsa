---
link: https://leetcode.com/problems/binary-tree-preorder-traversal/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "root, left, right"
time: "O(n)"
space: "O(n)"
date: 2023-01-04
---

# Problem
Preorder traversal.

# Approach
## Recursion
Root, left, right.

### Code
```cpp
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> x;
    if (root == NULL)
    {
        return x;
    }
    x.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    for (int i = 0; i < left.size(); i++)
    {
        x.push_back(left[i]);
    }
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
