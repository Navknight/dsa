---
link: https://leetcode.com/problems/reverse-nodes-in-k-group/
difficulty: Hard
topics:
  - "[[Linked Lists]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
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
