---
difficulty: Medium
topics:
  - Trees
  - DFS
  - Recursion
source: Leetcode
star: false
link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
date: 2026-06-29
---

[[Trees]] [[DFS]] [[Recursion]]

# Problem
Given preorder and inorder traversal arrays of a binary tree, reconstruct the tree.

# Approach
## Naive Slice (O(n²))
Same recursive split but copy vector slices at each level. `idx` = root's position in inorder = left subtree size. Use that to slice both arrays. Passing temporaries to `vector<int>&` won't compile: store slices in named variables first.

### Code
```cpp
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);

    int idx = 0;
    for (idx = 0; idx < inorder.size(); idx++)
        if (inorder[idx] == preorder[0]) break;

    vector<int> lp(preorder.begin()+1, preorder.begin()+1+idx);
    vector<int> li(inorder.begin(), inorder.begin()+idx);
    vector<int> rp(preorder.begin()+1+idx, preorder.end());
    vector<int> ri(inorder.begin()+idx+1, inorder.end());
    root->left  = buildTree(lp, li);
    root->right = buildTree(rp, ri);
    return root;
}
```

### Complexity
- Time: $O(n^2)$: O(n) copy per level
- Space: $O(n^2)$: slices at each level

## DFS with Index Boundaries
Preorder[0] is always root. Find root in inorder at index `mid`: everything left of `mid` is the left subtree, everything right is the right subtree. Left subtree has `mid` nodes in both arrays.

Instead of slicing vectors (O(n) copy per level), pass inorder boundaries `[inL, inR]` and advance a preorder index counter. Preorder visits root before children, so left recursion consumes left-subtree preorder nodes automatically: no explicit slicing needed.

Use a hashmap for O(1) inorder index lookup instead of linear scan.

### Code
```cpp
class Solution {
    unordered_map<int,int> mp;
    int preIdx = 0;

    TreeNode* build(vector<int>& pre, int inL, int inR) {
        if (inL > inR) return nullptr;
        int val = pre[preIdx++];
        TreeNode* root = new TreeNode(val);
        int mid = mp[val];
        root->left  = build(pre, inL, mid-1);
        root->right = build(pre, mid+1, inR);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        return build(preorder, 0, inorder.size()-1);
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$ hashmap + $O(h)$ recursion stack
