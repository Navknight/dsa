---
difficulty: Easy
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/subtree-of-another-tree/description/"
---

[[Trees]]

Just iterate over the tree and check if subtree is the same as the subRoot tree using [[Same Tree]]

```cpp
bool sameTree(TreeNode* t1, TreeNode* t2) {
	if(!t1 && !t2)  return true;
	if(!t1 || !t2) return false;
	if(t1->val != t2->val) return false;
	return sameTree(t1->left, t2->left) && sameTree(t2->right, t1->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	if(!root && !subRoot) return true;
	if(!root || !subRoot) return false;
	return sameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
```
