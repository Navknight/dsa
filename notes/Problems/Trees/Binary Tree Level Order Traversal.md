---
difficulty: Medium
topics:
  - Trees
  - BFS
source: Leetcode
star: false
link: https://leetcode.com/problems/binary-tree-level-order-traversal/
date: 2026-06-28
---

[[Trees]] [[BFS]]

# Problem
Return the level-order traversal of a binary tree's values as a 2D array (each level as a subarray).

# Approach
## BFS with Level Size Snapshot
Snapshot `q.size()` at start of each level: that's exactly how many nodes belong to current level. Process exactly that many, then save level and continue.

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
- Space: $O(n)$: queue holds at most one full level
