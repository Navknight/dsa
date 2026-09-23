---
link: https://leetcode.com/problems/reorder-list/
difficulty: Medium
topics:
  - "[[Linked Lists]]"
  - "[[Stack]]"
  - "[[Two Pointers]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "find the middle, reverse the second half, merge alternately"
time: "O(n)"
space: "O(1)"
date: 2023-04-10
---

# Problem
Reorder `L0 L1 ... Ln` into `L0 Ln L1 Ln-1 ...`.

# Approach
## Stack
Stack gives the nodes from the back. Alternate with the front.

### Code
```cpp
void reorderList(ListNode* head) {
    if(!head || !head->next)
        return;
    stack<ListNode*> st;
    ListNode* slow = head;
    int len = 0;
    while(slow){
        st.push(slow);
        slow = slow->next;
        len++;
    }

    slow = head;
    len /= 2;
    while(len){
        len--;

        ListNode* tmp = slow->next;
        slow->next = st.top();
        st.top()->next = tmp;
        slow = tmp;
        st.pop();

    }

    slow->next = nullptr;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Middle + Reverse + Merge
Slow and fast pointers find the middle. [[Reverse Linked List]] on the second half, then merge alternately.

### Code
```cpp
ListNode* reverse(ListNode* head) {
    if(!head || !head->next)
        return head;

    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

void reorderList(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow  = slow->next;
    }

    ListNode* second = reverse(slow->next);
    slow->next = nullptr;
    ListNode* first = head;

    while (first && second) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
