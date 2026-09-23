---
link: https://leetcode.com/problems/diameter-of-binary-tree/
difficulty: Easy
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "at each node max with lh + rh, return height up"
time: "O(n)"
space: "O(h)"
date: 2026-06-28
---

# Problem
Longest path between any two nodes, in edges.

# Approach
## DFS Height + Global Max
Path through a node = `lh + rh`. Track the max via ref, return height up.

GFG counts nodes, LC counts edges: `return res - 1`.

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
- Space: $O(h)$

## Return Pair
Return `{height, diameter}`, no ref needed.

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
