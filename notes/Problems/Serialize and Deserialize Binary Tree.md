---
link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
difficulty: Hard
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[BFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "preorder with \"N,\" for nulls, rebuild by consuming tokens in the same order"
time: "O(n)"
space: "O(n)"
date: 2026-06-30
---

# Problem
Serialize and deserialize any binary tree.

# Approach
## Preorder + Null Markers, Index
Preorder with `N,` for nulls. Deserialize with a shared `int& idx` scanning to each comma.

Trap: preorder + inorder without null markers breaks on duplicate values.

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
- Space: $O(h)$

## Preorder + Null Markers, Queue
Split into tokens once, consume from a queue.

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
- Space: $O(n)$
