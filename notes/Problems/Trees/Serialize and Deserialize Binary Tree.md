---
difficulty: Hard
topics: ["Trees"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/"
---

[[Trees]]

using [[stringstream]]

```cpp
void se(TreeNode* root, ostringstream& out) {
        if(!root)
            out << "# ";
        else {
            out << root->val << " ";
            se(root->left, out);
            se(root->right, out);
        }
    }

    TreeNode* de(istringstream& in) {
        string val;
        in >> val;
        if(val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = de(in);
        root->right = de(in);
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        se(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return de(in);
    }
```
