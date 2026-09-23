---
link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[BFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "BFS with level size, push every child"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Level-order traversal of an n-ary tree.

# Approach
## BFS with Two Level Vectors
`current` holds this level, collect every child into `next`, swap.

### Code
```cpp
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;

    vector<Node*>current;
    vector<Node*>next;
    current.push_back(root);
    while(!current.empty()){
        vector<int> level;
        for(int i = 0; i < current.size(); i++){
            Node* temp = current[i];
            level.push_back(temp->val);
            for(int j = 0; j < temp->children.size(); j++){
                next.push_back(temp->children[j]);
            }
        }
        ans.push_back(level);
        current.clear();
        current = next;
        next.clear();
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
