---
difficulty: Medium
topics: []
source: Leetcode
star: false
code: LeetCode/validate_binary_search_tree.cpp
---
[[LeetCode/validate_binary_search_tree.cpp]]
## Recursive
Recursive approach with tightening bounds as we traverse the tree. 
The left child will be smaller than the root but larger than the last node where we took a right child. The right child will be smaller than the last node where we took a left child and smaller than the root.
```cpp
bool helper(TreeNode* root, long low, long high) {
	if (!root) return true;
	if (root->val <= low || root->val >= high) return false;
	return helper(root->left, low, root->val) && 
		helper(root->right, root->val, high);
}

bool isValidBST(TreeNode* root) {
	return helper(root, LONG_MIN, LONG_MAX);
}
```

## Inorder Traversal
BST is strictly increasing in an inorder traversal.
```cpp
bool inorder(TreeNode* root, TreeNode*& prev) {
    if (!root) return true;

    if (!inorder(root->left, prev)) return false;

    if (prev && root->val <= prev->val) return false;
    prev = root;

    return inorder(root->right, prev);
}

bool isValidBST(TreeNode* root) {
    TreeNode* prev = nullptr;
    return inorder(root, prev);
}
```

Prev needs to be passed by reference so that the value of previous can backpropagate. Not passing it by reference will make copies and it wont backpropagate.