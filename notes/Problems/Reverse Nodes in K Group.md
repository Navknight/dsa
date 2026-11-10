---
link: https://leetcode.com/problems/reverse-nodes-in-k-group/
difficulty: Hard
topics:
  - "[[Linked Lists]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: false
mastery: red
review: 2026-11-11
insight: "check k nodes exist, reverse k, recurse on rest and attach to old head"
time: "O(n)"
space: "O(n/k)"
date: 2026-06-28
---

# Problem
Reverse every `k` nodes. A last group smaller than `k` stays as is.

# Approach
## Recursive Chunks
Check `k` nodes exist, else return `head`. Reverse `k` nodes, old head becomes the tail. Recurse on the rest and attach it to the old head. Return the new head.

### Mistakes
- First reversal loop overwrote `ptr->next->next` and read it back as the original, made a cycle `1 <-> 2`. Save `curr->next` first, then point it at `prev`
- Forgot the `return` at the end, it must return the new head (`prev`), not `head`
- The check did `count++` on the step that walked off the end, so `[5]` with `k = 2` passed and crashed. Test `ptr` before stepping
- Left a stale `count = 1` / `if (count < k) return head;` after changing the check. `1 < k` is always true, so it returned `head` unchanged

### Code
```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* fast = head;

        int n = 0;
        while(n < k && fast) {
            fast = fast->next;
            n++;
        }

        if(n < k) return head;

        ListNode* dummy = head;
        ListNode* slow = nullptr;

        while(n--) {
            ListNode* temp = dummy->next;
            dummy->next = slow;
            slow = dummy;
            dummy = temp;
        }

        dummy = reverseKGroup(dummy, k);
        head->next = dummy;
        return slow;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n/k)$

## Iterative
Dummy node plus `groupPrev`. Find the `k`-th node, reverse with `prev` starting at `groupNext` so the tail links forward, then hook `groupPrev->next = kth` and move `groupPrev` to the old first node. No recursion stack.

### Code
```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0, head);
    ListNode* groupPrev = &dummy;

    while (true) {
        ListNode* kth = groupPrev;
        for (int i = 0; i < k && kth; i++) kth = kth->next;
        if (!kth) break;

        ListNode* groupNext = kth->next;
        ListNode* prev = groupNext;
        ListNode* curr = groupPrev->next;
        while (curr != groupNext) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* tail = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = tail;
    }
    return dummy.next;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
