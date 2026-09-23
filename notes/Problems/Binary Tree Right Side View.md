---
link: https://leetcode.com/problems/binary-tree-right-side-view/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[BFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "level-order BFS, take the last node of each level (n == 0 after decrement)"
time: "O(n)"
space: "O(n)"
date: 2026-06-28
---

# Problem
Return the rightmost value at each level.

# Approach
## BFS, Last Node Per Level
Level-order with size snapshot, push the value when `n == 0`.

Trap: `q.empty()` doesn't mark the last node, children are already in the queue.

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
- Space: $O(n)$
