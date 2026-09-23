---
link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "preorder[i] is the root, its inorder index splits left/right. hashmap + inorder bounds"
time: "O(n)"
space: "O(n)"
date: 2026-06-29
---

# Problem
Build the tree from preorder and inorder.

# Approach
## Slicing
Root = `preorder[0]`, its inorder index `idx` = left subtree size. Slice both arrays and recurse. Store slices in named vectors, temporaries don't bind to `vector<int>&`.

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
- Time: $O(n^2)$
- Space: $O(n^2)$

## Index Bounds + Hashmap
Pass inorder bounds `[inL, inR]` and a global preorder index instead of slicing. Hashmap for inorder lookups.

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
- Space: $O(n)$
