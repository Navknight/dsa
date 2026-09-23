---
link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[BFS]]"
  - "[[Linked Lists]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "walk each level with the next pointers already set, wire the level below"
time: "O(n)"
space: "O(1)"
date: 2023-02-13
---

# Problem
Set each node's `next` to its right neighbour in a perfect binary tree.

# Approach
## Level Walk
Walk level `lnode` using `next`. `left->next = right`, and `right->next = next->left` across parents. Then drop to `lnode->left`.

### Code
```cpp
Node* connect(Node *root)
{
    if(root == NULL) return root;

        Node* lnode = root;
        while(lnode->left != NULL){
            Node* head = lnode;
            while(head != NULL){
                head->left->next = head->right;
                if(head->next != NULL){
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            lnode = lnode->left;
        }
        return root;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
