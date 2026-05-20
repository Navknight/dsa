---
difficulty: Easy
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/same-tree/description/"
---

[[Trees]]

Check if both are not null, then check if their values are different, now repeat for the subtrees.

```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
	if(!p && !q)
		return true;
	if(!p || !q)
		return false;
	if (p->val != q->val)
		return false;
	return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
```
