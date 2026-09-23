---
link: https://leetcode.com/problems/linked-list-in-binary-tree/
difficulty: Medium
topics:
  - "[[Trees]]"
  - "[[DFS]]"
  - "[[Linked Lists]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "from every tree node try to match the list downward"
time: "O(n * m)"
space: "O(h)"
date: 2023-04-10
---

# Problem
Is the linked list a downward path in the binary tree?

# Approach
## DFS
From every tree node, try to match `head` going down left or right.

### Code
```cpp
bool is(ListNode *h, TreeNode *r)
{
    if (!h)
        return true;
    if (!r)
        return false;
    if (h->val == r->val)
        return is(h->next, r->right) || is(h->next, r->left);
    return false;
}

bool isSubPath(ListNode *head, TreeNode *root)
{
    if (!root)
        return false;
    if(is(head, root)) return true;
    return isSubPath(head, root->left)||isSubPath(head, root->right);
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(h)$
