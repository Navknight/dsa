---
difficulty: Hard
topics:
  - Linked Lists
  - Recursion
source: Leetcode
star: true
link: https://leetcode.com/problems/reverse-nodes-in-k-group/
date: 2026-06-28
---

[[Linked Lists]] [[Recursion]]

# Problem
Given head of a linked list, reverse every k nodes. If remaining nodes < k, leave them as-is.

# Approach
## Recursive Reversal in Chunks

Recursively reverse the list in chunks of k. Use a fast pointer to check k nodes exist: if not, return head unchanged.

For the reversal: `dummy` trails the current node being reversed, `slow` trails behind it (starts at `nullptr`). After reversing k nodes with `while(n--)`, the original head becomes the new tail and `slow` becomes the new head of the reversed chunk.

Recurse on `dummy` (first node of next chunk). The recursive call returns the new head of the remaining list, attach it to `dummy` (old head, now tail). Return `slow` (new head of this chunk).

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
- Space: $O(n/k)$ recursion stack
