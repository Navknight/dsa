---
difficulty: Easy
topics: ["Recursion", "Dynamic Programming"]
source: Standard
star: false
---

[[Recursion]] [[Dynamic Programming]]

# Problem
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

# Solution

The diameter can either pass through a node and move up, or it can be the left subtree + right subtree + node

```cpp
int solve(Node* root, int &res){
    if(root == NULL)
        return 0;
    int left = solve(root->left, res);
    int right = solve(root->right, res);
    int temp = max(left, right) + 1;
    int ans = right + left + 1;
    res = max(res, ans);
    return temp;
}

int diameter(Node* root) {
    // Your code here
    int res = 0;
    int temp = solve(root, res);
    return res;
}
```
