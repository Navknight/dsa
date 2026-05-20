---
difficulty: Medium
topics: ["Linked Lists", "Stack", "Two Pointers"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/"
---

[[Linked Lists]] [[Stack]] [[Two Pointers]]

1. Stack - use a stack to store all the nodes and then pop n nodes from the top to reach the node before the node that needs to be removed.
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

2. Two Pointers - Maintain two pointers, one traverses the list with a delay of n+1 steps so that it points to the node before the one that needs to be deleted.

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