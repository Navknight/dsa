---
link: https://leetcode.com/problems/intersection-of-two-linked-lists/
difficulty: Easy
topics:
  - "[[Linked Lists]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "advance the longer list by the length difference, then walk both together"
time: "O(n + m)"
space: "O(1)"
date: 2023-06-13
---

# Problem
Node where two linked lists merge.

# Approach
## Equalize Lengths
Get both lengths, move the longer head forward by the difference, then walk both until they meet.

### Code
```cpp
int len (ListNode* root){
    int l = 0;
    while(root){
        root = root->next;
        l++;
    }
    return l;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int la = len(headA);
    int lb = len(headB);

    while(la > lb){
        headA = headA->next;
        la--;
    }
    while(lb > la){
        headB = headB->next;
        lb--;
    }

    while(headA != headB){
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}
```

### Complexity
- Time: $O(n + m)$
- Space: $O(1)$
