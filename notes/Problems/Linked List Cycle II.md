---
link: https://leetcode.com/problems/linked-list-cycle-ii/
difficulty: Medium
topics:
  - "[[Linked Lists]]"
  - "[[Two Pointers]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "after slow and fast meet, one pointer from head and one from the meeting point meet at the cycle start"
time: "O(n)"
space: "O(1)"
date: 2022-12-11
---

# Problem
Return the node where the cycle begins, or null.

# Approach
## Floyd's
Same as [[Linked List Cycle]]. After they meet, start `slow2` at head and move both one step, they meet at the entry. Same trick as [[Find the Duplicate Number]].

### Code
```cpp
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            ListNode *slow2 = head;
            while (slow2 != slow)
            {
                slow2 = slow2->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
