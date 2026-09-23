---
link: https://leetcode.com/problems/linked-list-cycle/
difficulty: Easy
topics:
  - "[[Linked Lists]]"
  - "[[Two Pointers]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "slow 1 step, fast 2 steps, they meet if there is a cycle"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Does the list have a cycle?

# Approach
## Floyd's
`fast` moves 2 steps, `slow` moves 1. They meet only if there's a cycle.

### Code
```cpp
bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps
        if (slow == fast) return true; // cycle found
    }
    return false; // reached end → no cycle
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
