---
difficulty: Medium
topics:
  - Trees
  - BFS
source: Leetcode
star: false
link: https://leetcode.com/problems/binary-tree-right-side-view/
date: 2026-06-28
---

[[Trees]] [[BFS]]

# Problem
Given root of a binary tree, return the values visible from the right side (rightmost node at each level).

# Approach
## BFS Level Order: Last Node Per Level
Standard level-order BFS with size snapshot. At each level, only push the last node's value (`n == 0` after decrement).

Trap: don't use `q.empty()` to detect last node, children already pushed before queue drains, so it's never empty at the right moment.

### Code
```cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            TreeNode* node = q.front(); q.pop();
            if (n == 0) ans.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$ queue holds at most one full level
