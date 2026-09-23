---
link: https://leetcode.com/problems/add-two-numbers/
difficulty: Medium
topics:
  - "[[Linked Lists]]"
  - "[[Math]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "dummy head, loop while l1 || l2 || carry"
time: "O(max(n, m))"
space: "O(max(n, m))"
date: 2026-06-27
---

# Problem
Add two numbers stored in reverse-order linked lists.

# Approach
## Dummy Head + Carry
Digits are LSB first so add in one pass. Loop while either list or carry is left (handles 999 + 1).

### Code
```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
    }
    return dummy.next;
}
```

### Complexity
- Time: $O(\max(n, m))$
- Space: $O(\max(n, m))$ for the output
