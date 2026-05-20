---
difficulty: Hard
topics: ["Linked Lists"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/merge-k-sorted-lists/description/"
---

[[Linked Lists]]

Merging k lists is the same as merging two lists k-1 times. So use [[Merge Two Sorted Lists]] k-1 times and merge it. 

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
