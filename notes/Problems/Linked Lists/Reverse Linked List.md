---
difficulty: Easy
topics: ["Linked Lists"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/reverse-linked-list/"
---

[[Linked Lists]]

Base Case - singleton list, empty linked list.
- `newHead` is the head of the reversed list
- redirect `head->next->next` to point back to `head`
- cutoff head to point to `nullptr` to avoid cycles.

```cpp
ListNode* reverseList(ListNode* head) {
	if(!head || !head->next)
		return head;

	ListNode* newHead = reverseList(head->next);

	head->next->next = head;
	head->next = nullptr;

	return newHead;
}
```
