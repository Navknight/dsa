---
difficulty: Easy
topics: ["Linked Lists", "Two Pointers"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/linked-list-cycle/description/"
---

[[Linked Lists]] [[Two Pointers]]

## Floyd's Cycle Detection Algo
Have two pointers - `fast` and `slow`. One pointer moves at twice the speed of the other, so they are bound to meet each other if there is a cycle.

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

