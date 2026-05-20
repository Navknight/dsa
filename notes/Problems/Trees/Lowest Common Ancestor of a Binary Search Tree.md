---
difficulty: Medium
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/"
---

[[Trees]]

The LCA will either be one of the nodes mentioned, or it will be the point where p and q are on opposite sides of the node because it is a binary search tree.

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int low = min(p->val, q->val);
	int high = max(p->val, q->val);

	if(root->val > high) return lowestCommonAncestor(root->left, p, q);
	if(root->val < low) return lowestCommonAncestor(root->right, p, q);
	else return root;
}
```
