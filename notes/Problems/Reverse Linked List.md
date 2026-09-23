---
link: https://leetcode.com/problems/reverse-linked-list/
difficulty: Easy
topics:
  - "[[Linked Lists]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "recursive: reverse the rest, head->next->next = head, head->next = null"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Reverse a linked list.

# Approach
## Recursion
Reverse the rest to get `newHead`. Point `head->next->next` back at `head`, cut `head->next` to avoid a cycle.

### Code
```cpp
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
