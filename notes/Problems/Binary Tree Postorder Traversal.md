---
link: https://leetcode.com/problems/binary-tree-postorder-traversal/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "left, right, root"
time: "O(n)"
space: "O(n)"
date: 2023-01-04
---

# Problem
Postorder traversal.

# Approach
## Recursion
Left, right, root.

### Code
```cpp
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> x;
    if (!root)
    {
        return x;
    }
    vector<int> left = postorderTraversal(root->left);
    for (int i = 0; i < left.size(); i++)
    {
        x.push_back(left[i]);
    }
    vector<int> right = postorderTraversal(root->right);
    for (int i = 0; i < right.size(); i++)
    {
        x.push_back(right[i]);
    }
    x.push_back(root->val);
    return x;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
