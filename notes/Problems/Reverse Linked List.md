---
link: https://leetcode.com/problems/reverse-linked-list/
difficulty: Easy
topics:
  - "[[Linked Lists]]"
source: Leetcode
star: true
blind75: true
mastery: yellow
review: 2026-11-14
insight: "iterative: save next, flip curr->next to prev, advance both. Recursive: head->next->next = head, head->next = null"
time: "O(n)"
space: "O(n)"
date: 2026-11-11
---

# Problem
Reverse a linked list.

# Approach
## Iterative
Keep `prev` and `curr`. Save `curr->next`, point `curr` back at `prev`, move both forward. `prev` is the new head when `curr` is null.

### Mistakes
- Did `prev = curr` before saving `next`, lost the rest of the list
- Returned `dummy->next`, there is no dummy. Return `prev`

### Code
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

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
