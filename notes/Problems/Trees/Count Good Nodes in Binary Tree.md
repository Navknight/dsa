---
difficulty: Medium
topics:
  - Trees
  - DFS
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
date: 2026-06-28
---

[[Trees]] [[DFS]] [[Recursion]]

# Problem
Count nodes where no ancestor has a greater value (node val >= max on path from root).

# Approach
## DFS with Path Maximum
Pass current path max down by value. At each node, update max, then check if node qualifies. Count good nodes bottom-up.

Trap: pass `m` by value not reference. Reference leaks left-branch updates into right branch, corrupting the path max.

### Code
```cpp
int solve(TreeNode* root, int m) {
    if (!root) return 0;
    m = max(root->val, m);
    int l = solve(root->left, m);
    int r = solve(root->right, m);
    return (m <= root->val) ? l + r + 1 : l + r;
}

int goodNodes(TreeNode* root) {
    return solve(root, INT_MIN);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$: recursion stack
