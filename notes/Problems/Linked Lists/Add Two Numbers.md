---
difficulty: Medium
topics:
  - Linked Lists
  - Math
source: Leetcode
star: false
link: https://leetcode.com/problems/add-two-numbers/
date: 2026-06-27
---

[[Linked Lists]] [[Math]]

# Problem
Two non-empty linked lists represent non-negative integers stored in reverse order (LSB first). Add the two numbers and return the sum as a linked list in the same format.

# Approach
## Dummy Head + Carry
Digits are already LSB-first so traverse both lists simultaneously, summing digits and propagating carry. Dummy head avoids special-casing the first node. Loop continues while either list has nodes or carry is non-zero (handles overflow like 999 + 1).

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
- Time: $O(max(n, m))$
- Space: $O(max(n, m))$: output list
