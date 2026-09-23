---
link: https://leetcode.com/problems/merge-k-sorted-lists/
difficulty: Hard
topics:
  - "[[Linked Lists]]"
  - "[[Heap]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "min heap of list heads, or merge pairwise. merging one by one is O(kN)"
time: "O(k * N)"
space: "O(1)"
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
