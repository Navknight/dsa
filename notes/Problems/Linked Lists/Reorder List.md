---
difficulty: Medium
topics: ["Linked Lists", "Stack", "Two Pointers"]
source: Leetcode
star: false
code: LeetCode/reorder_list.cpp
---
[[LeetCode/reorder_list.cpp]]
[[Linked Lists]] [[Stack]] [[Two Pointers]]

[Reorder List]([Reorder List - LeetCode](https://leetcode.com/problems/reorder-list/submissions/931432638/?envType=study-plan&id=programming-skills-ii)) 
1.  approach - fill a stack while traversing a linked list, so now the last element is on the top, now use the head and the stack to create an alternating linked list

```cpp
void reorderList(ListNode* head) {
	if(!head || !head->next)
		return;
	stack<ListNode*> st;
	ListNode* slow = head;
	int len = 0;
	while(slow){
		st.push(slow);
		slow = slow->next;
		len++;
	}

	slow = head;
	len /= 2;
	while(len){
		len--;

		ListNode* tmp = slow->next;
		slow->next = st.top();
		st.top()->next = tmp;
		slow = tmp;
		st.pop();

	}

	slow->next = nullptr;
}
```

2.  Pointer approach - Use a fast and slow pointer to find the mid part of the linked list Now [[Reverse Linked List]] the second half of the list and the use two pointers, first(head) and second(last) along with a temp pointer to create an alternating list.

```cpp
ListNode* reverse(ListNode* head) {
	if(!head || !head->next)
		return head;
	
	ListNode* newHead = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return newHead;
}

void reorderList(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;

	while(fast && fast->next){
		fast = fast->next->next;
		slow  = slow->next;
	}

	ListNode* second = reverse(slow->next);
	slow->next = nullptr;
	ListNode* first = head;

	while (first && second) {
		ListNode* tmp1 = first->next;
		ListNode* tmp2 = second->next;

		first->next = second;
		second->next = tmp1;

		first = tmp1;
		second = tmp2;
	}
}
```