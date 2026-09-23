---
link: https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
difficulty: Easy
topics:
  - "[[Recursion]]"
  - "[[Trees]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "same as LC diameter but counted in nodes, l + r + 1"
time: "O(n)"
space: "O(h)"
date: 
---

# Problem
Number of nodes on the longest path between two leaves. Nodes version of [[Diameter of Binary Tree]].

# Approach
## DFS Height + Global Max
Path through node = `l + r + 1`, return `max(l, r) + 1`.

### Code
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

### Complexity
- Time: $O(n)$
- Space: $O(h)$
