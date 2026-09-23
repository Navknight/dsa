---
link: https://leetcode.com/problems/remove-linked-list-elements/
difficulty: Easy
topics:
  - "[[Linked Lists]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "dummy head, skip every node equal to val"
time: "O(n)"
space: "O(1)"
date: 2022-12-11
---

# Problem
Remove all nodes with value `val`.

# Approach
## Skip Matches
Drop matching heads first. Then `prev` trails `curr`, a match rewires `prev->next` past it. A dummy head would remove the head special case.

### Code
```cpp
ListNode *removeElements(ListNode *head, int val)
{
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }
    ListNode *curr = new ListNode();
    curr->next = head;
    ListNode *prev = new ListNode();
    prev->next = head;
    while (curr != NULL && curr->next != NULL)
    {
        curr = curr->next;
        if (curr->val == val)
        {
            prev->next = curr->next;
            // curr = curr->next;
        }
        else
        {
            prev = prev->next;
        }
    }
    return head;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
