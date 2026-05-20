---
difficulty: Medium
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/"
---

[[Trees]]

# Brute Force
Inorder traversal in a BST is always increasing in value, so make an array from the BST using inorder traversal and return the kth smallest element.

```cpp
int inorder(TreeNode* root, int& k){
	if(!root) return -1;

	int l = inorder(root->left, k);
	if(l != -1) return l;

	k--;
	if(k == 0) return root->val;

	return inorder(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
	return inorder(root, k);
}
```


