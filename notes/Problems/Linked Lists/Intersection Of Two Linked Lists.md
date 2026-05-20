---
difficulty: Easy
topics: ["Linked Lists"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/intersection-of-two-linked-lists/"
code: LeetCode/intersection_of_two_linked_lists.cpp
---
[[LeetCode/intersection_of_two_linked_lists.cpp]]
[[Linked Lists]]

We are given two heads of two singly linked lists which become one at a particular node. We need to find which node that is.

Since both the linked list will have unequal lengths, we can first calculate the length of both the linked lists and move the pointer forward in the longer one such that the length is now equal, since after intersection the length of the linked lists will be equal 

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
