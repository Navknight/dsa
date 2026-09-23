---
link: https://leetcode.com/problems/binary-tree-level-order-traversal/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[BFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "BFS, snapshot q.size() at the start of each level"
time: "O(n)"
space: "O(n)"
date: 2026-06-28
---

# Problem
Return the level-order traversal, one array per level.

# Approach
## BFS with Level Size
Snapshot `q.size()` at the start of each level and pop exactly that many.

### Code
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<TreeNode*> mq;
    mq.push(root);
    while (!mq.empty()) {
        int n = mq.size();
        vector<int> lv;
        while (n--) {
            TreeNode* curr = mq.front(); mq.pop();
            lv.push_back(curr->val);
            if (curr->left)  mq.push(curr->left);
            if (curr->right) mq.push(curr->right);
        }
        ans.push_back(lv);
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
