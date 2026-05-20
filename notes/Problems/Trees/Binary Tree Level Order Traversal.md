---
difficulty: Medium
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/binary-tree-level-order-traversal/description/"
code: LeetCode/binary_tree_level_order_traversal.cpp
---
[[LeetCode/binary_tree_level_order_traversal.cpp]]
[[Trees]]

Maintain an array of each level and push the array to the ans array
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ans;
	if(!root) return ans;

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();
		vector<int> curr;

		while(n--) {
			TreeNode* node = q.front(); q.pop();
			curr.push_back(node->val);
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}

		ans.push_back(curr);
	}

	return ans;
}
```
