---
link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
difficulty: Medium
topics:
  - "[[Linked Lists]]"
  - "[[Stack]]"
  - "[[Two Pointers]]"
source: Leetcode
star: true
blind75: true
mastery: yellow
review: 2026-11-11
insight: "dummy head, move first n+1 ahead, move both until first is null, second is before the target"
time: "O(n)"
space: "O(1)"
date: 2026-11-08
---

# Problem
Remove the `n`th node from the end.

# Approach
## Stack
Push all nodes, pop `n` to reach the node before the target.

### Code
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    stack<ListNode*> st;
    ListNode* ptr = head;
    st.push(nullptr);
    while(ptr){
        st.push(ptr);
        ptr = ptr->next;
    }

    while(n--){
        st.pop();
    }

    ptr = st.top(); st.pop();
    if(!ptr){
        return head->next;
    }
    ptr->next = ptr->next->next;

    return head;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Two Pointers
Dummy head. `first` goes `n + 1` ahead, then move both. `second` stops right before the node to delete.

### Code
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* first = dummy;
    ListNode* second = dummy;

    for(int i  = 0; i <= n; i++)
        first = first->next;

    while(first){
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    return dummy->next;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

- Both pointers on the dummy, move `fast` n times, then move both while `fast->next`
- Keep a separate pointer to the dummy, `slow` walks and the dummy is lost otherwise
- Use `ListNode dummy(0, head)` on the stack, `new` leaks
- Tests: `[1,2,3,4,5]` n=2, `[1]` n=1 gives empty, `[1,2]` n=2 gives `[2]`

### Mistakes
- Gap was off by one. `slow` must end on the node before the target
- `return head` is wrong when the head is removed. Return `dummy->next`
