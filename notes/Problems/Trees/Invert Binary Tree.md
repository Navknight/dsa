---
difficulty: Easy
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/invert-binary-tree/description/"
---

[[Trees]]

Invert the right and left, then place the inverted right to left and inverted left to right

```cpp
TreeNode* invertTree(TreeNode* root) {
	if(root == nullptr) return nullptr;

	TreeNode* temp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(temp);

	return root;
}
```

