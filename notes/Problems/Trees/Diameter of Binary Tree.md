---
difficulty: Easy
topics:
  - Trees
  - DFS
  - Recursion
source: Leetcode
star: true
link: https://leetcode.com/problems/diameter-of-binary-tree/
date: 2026-06-28
---

[[Trees]] [[DFS]] [[Recursion]]

# Problem
Find the length of the diameter of a binary tree: the longest path between any two nodes. Length is measured in edges, not nodes.

# Approach
## DFS Height + Global Max
At every node, the longest path through it is `left_height + right_height` (edges). Track max across all nodes via ref. Return height (not diameter) up the call stack so parent can use it.

Gotcha vs GFG variant: GFG counts nodes, LC counts edges. Same logic, just `return res - 1` at the end.

### Code
```cpp
int dia(TreeNode* root, int& res) {
    if (!root)
        return 0;

    int left = dia(root->left, res);
    int right = dia(root->right, res);
    int temp = max(left, right) + 1;
    int take = left + right + 1;  // node count on path through this node
    res = max(res, take);

    return temp;  // height
}

int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    dia(root, res);
    return res - 1;  // convert node count → edge count
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$: recursion stack

## Return Pair (no side effects)
Same idea, but return `{height, diameter}` so no ref needed.

### Code
```cpp
pair<int,int> dia(TreeNode* root) {
    if (!root) return {0, 0};
    auto [lh, ld] = dia(root->left);
    auto [rh, rd] = dia(root->right);
    return {max(lh, rh) + 1, max({ld, rd, lh + rh})};
}

int diameterOfBinaryTree(TreeNode* root) {
    return dia(root).second;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$
