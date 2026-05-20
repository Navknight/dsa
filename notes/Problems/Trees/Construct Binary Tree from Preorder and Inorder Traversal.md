---
difficulty: Medium
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/"
---

[[Trees]]

The first element of the preorder traversal is always the root node. The inorder traversal splits the bst into two halves - left and right.

```cpp
unordered_map<int, int> inorderIdx;
    int preIdx;

    TreeNode* dfs(vector<int> &preorder, int left, int right){
        if(preorder.empty() || left > right) return nullptr;

        int mid = inorderIdx[preorder[preIdx]];
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = dfs(preorder, left, mid -1);
        root->right = dfs(preorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inorderIdx[inorder[i]] = i;
        }
        preIdx = 0;
        return dfs(preorder, 0, inorder.size()-1);
    }
```
