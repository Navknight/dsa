---
difficulty: Hard
topics:
  - Trees
  - DFS
  - BFS
source: Leetcode
star: false
link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
date: 2026-06-30
---

[[Trees]] [[DFS]]

# Problem
Serialize a binary tree to a string and deserialize it back. Must handle any binary tree (not just BST), including duplicates.

# Approach
## Preorder with Null Markers (Raw Index)
Preorder DFS. Encode nulls explicitly as "N," so structure is unambiguous. On deserialize, walk raw string with `int& idx` shared across all calls: finds each token by scanning to next comma.

Trap: preorder + inorder without null markers fails with duplicate values.

### Code
```cpp
string serialize(TreeNode* root) {
    if (!root) return "N,";
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

TreeNode* desc(string& data, int& idx) {
    if (idx >= data.size() || data[idx] == 'N') { idx += 2; return nullptr; }
    int len = idx;
    while (len < data.size() && data[len] != ',') len++;
    string num = data.substr(idx, len - idx);
    idx = len + 1;
    TreeNode* root = new TreeNode(stoi(num));
    root->left  = desc(data, idx);
    root->right = desc(data, idx);
    return root;
}

TreeNode* deserialize(string data) {
    int idx = 0;
    return desc(data, idx);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(h)$ recursion stack

## Preorder with Null Markers (Queue: Cleaner)
Same encoding. Split into tokens once upfront, consume from queue front. No index arithmetic, no manual substr parsing.

### Code
```cpp
string serialize(TreeNode* root) {
    if (!root) return "N,";
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

TreeNode* build(queue<string>& q) {
    string val = q.front(); q.pop();
    if (val == "N") return nullptr;
    TreeNode* node = new TreeNode(stoi(val));
    node->left  = build(q);
    node->right = build(q);
    return node;
}

TreeNode* deserialize(string data) {
    queue<string> q;
    stringstream ss(data);
    string token;
    while (getline(ss, token, ',')) q.push(token);
    return build(q);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$ queue + $O(h)$ recursion stack
