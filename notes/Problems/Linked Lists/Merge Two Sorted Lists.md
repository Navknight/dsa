---
difficulty: Easy
topics: ["Linked Lists", "Two Pointers"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/merge-two-sorted-lists/description/"
---

[[Linked Lists]] [[Two Pointers]]

attach the smaller nodes till one of the lists finishes. 
Then just attach the remaining part of the remaining list at the end.

```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ans = new ListNode();
    ListNode* temp = ans;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1) temp->next = list1;
    if (list2) temp->next = list2;

    return ans->next;
}
```
