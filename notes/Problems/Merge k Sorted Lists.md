---
link: https://leetcode.com/problems/merge-k-sorted-lists/
difficulty: Hard
topics:
  - "[[Linked Lists]]"
  - "[[Heap]]"
source: Leetcode
star: true
blind75: true
mastery: yellow
review: 2026-11-13
insight: "min heap of list heads, or merge pairwise. merging one by one is O(kN)"
time: "O(N log k)"
space: "O(k)"
date: 
---

# Problem
Merge `k` sorted linked lists.

# Approach
## Merge One by One
[[Merge Two Sorted Lists]] `k - 1` times. Simple but each merge rewalks the growing result. A min heap of heads makes it $O(N \log k)$.

### Code
```cpp
ListNode* merge2(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode();
    ListNode* temp = ans;

    while(l1 && l2){
        if(l1->val < l2->val){
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if(l1) temp->next = l1;
    if(l2) temp->next = l2;

    return ans->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if(n == 1) return lists[0];
    if(n == 0) return nullptr; 
    ListNode* ans = new ListNode();
    ans = lists[0];
    for(int i = 1; i < n; i++){
        ans = merge2(ans, lists[i]);
    }

    return ans;
}
```

### Complexity
- Time: $O(k \cdot N)$
- Space: $O(1)$

## Pairwise Queue
Push every list into a queue, pop two, merge, push the result back. Each pass halves the number of lists, so about `log k` rounds and every node is touched once per round.

- Merging into one running result is `O(k * N)`, the result gets longer each time
- Min heap of the `k` heads is the same `O(N log k)` with `O(k)` space. In-place version: `lists[i] = merge(lists[i], lists[i + step])` with `step` doubling, no queue
- `new ListNode()` in `merge` leaks one node per call, use a stack dummy

### Mistakes
- `temp->next = node1->val` assigned an int to a node pointer, link the node itself
- No check for an empty `lists`, `q.front()` on an empty queue is UB

### Code
```cpp
class Solution {
   public:
    ListNode* merge(ListNode* node1, ListNode* node2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        while (node1 && node2) {
            if (node1->val < node2->val) {
                temp->next = node1;
                node1 = node1->next;
            } else {
                temp->next = node2;
                node2 = node2->next;
            }
            temp = temp->next;
        }

        if (node1)
            temp->next = node1;
        else
            temp->next = node2;

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        queue<ListNode*> q;
        for (auto& l : lists) q.push(l);

        while (q.size() > 1) {
            ListNode* l1 = q.front();
            q.pop();
            ListNode* l2 = q.front();
            q.pop();

            q.push(merge(l1, l2));
        }

        return q.front();
    }
};
```

### Complexity
- Time: $O(N \log k)$
- Space: $O(k)$
