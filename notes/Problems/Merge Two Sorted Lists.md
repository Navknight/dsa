---
link: https://leetcode.com/problems/merge-two-sorted-lists/
difficulty: Easy
topics:
  - "[[Linked Lists]]"
  - "[[Two Pointers]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "dummy head, attach the smaller node, append the leftover list"
time: "O(n + m)"
space: "O(1)"
date: 
---

# Problem
Merge two sorted linked lists.

# Approach
## Dummy Head
Attach the smaller head each step, then append whatever is left.

### Code
```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ans = new ListNode();
    ListNode* temp = ans;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1) temp->next = list1;
    if (list2) temp->next = list2;

    return ans->next;
}
```

### Complexity
- Time: $O(n + m)$
- Space: $O(1)$
