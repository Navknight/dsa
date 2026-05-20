---
difficulty: Easy
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/maximum-depth-of-binary-tree/description/"
---

[[Trees]]

current node (1 length) + the max length between its children subtrees.

```cpp
int maxDepth(TreeNode* root) {
	if(root == nullptr) return 0;

	return max(maxDepth(root->right), maxDepth(root->left)) + 1;
}
```
