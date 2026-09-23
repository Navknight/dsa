---
link: https://leetcode.com/problems/sum-of-left-leaves/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "at each node, if left child is a leaf add it, else recurse into it"
time: "O(n)"
space: "O(h)"
date: 2023-03-11
---

# Problem
Sum of all left leaves.

# Approach
## DFS
If `left` is a leaf, add it. Else recurse left. Always recurse right.

### Code
```cpp
int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    if (root == NULL)
        return 0;
    if (root->left != NULL)
    {
        if (root->left->left == NULL && root->left->right == NULL)
            sum += root->left->val;
        else
            sum += sumOfLeftLeaves(root->left);
    }
    sum += sumOfLeftLeaves(root->right);
    return sum;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
