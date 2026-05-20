---
difficulty: Hard
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/binary-tree-maximum-path-sum/description/"
---

[[Trees]]

For each node we track two things ->

### Gain
The maximum sum you can get if you continue upwards, eg -> left child + current. we cant include right in this as that would not be a path upward.

### Path
The maximum possible sum at the current node -> left + right + current. This is what we return.

```cpp
int path(TreeNode* root, int &c){
	if(!root) return 0;

	int left = max(0,path(root->left, c));
	int right = max(0,path(root->right, c));
	c = max(root->val + left + right, c);
	return max(left, right) + root->val;
}

int maxPathSum(TreeNode* root) {
	int c = INT_MIN;
	path(root, c);
	return c;
}
```
