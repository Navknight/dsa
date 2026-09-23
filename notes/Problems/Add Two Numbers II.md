---
link: https://leetcode.com/problems/add-two-numbers-ii/
difficulty: Medium
topics:
  - "[[Stack]]"
  - "[[Linked Lists]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "most significant digit first, push both lists on stacks and add while popping"
time: "O(n + m)"
space: "O(n + m)"
date: 2023-05-18
---

# Problem
Add two numbers stored in linked lists, most significant digit first.

# Approach
## Stacks
Push both lists onto stacks. Pop and add with carry, prepend each new node to the result.

Bug in my code: the loop condition should be `!s1.empty() || !s2.empty() || carry`, the `&& carry != 0` never runs on a 0 carry.

### Code
```cpp
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<ListNode*> s1;
    stack<ListNode*> s2;

    ListNode* ans = new ListNode();

    while(l1){
        s1.push(l1);
        l1 = l1->next;
    }
    while(l2){
        s2.push(l2);
        l2 = l2->next;
    }

    int carry = 0;
    while((!s1.empty() || !s2.empty()) && carry != 0){
        int x = (s1.empty())?0:s1.top()->val;
        if(!s1.empty()) s1.pop();
        int y = (s2.empty())?0:s2.top()->val;
        if(!s2.empty()) s2.pop();

        int sum = x + y + carry;
        carry = sum/10;
        ListNode* temp = new ListNode(sum%10);

        temp->next = ans->next;
        ans->next = temp;
    }

    return ans->next;
}
```

### Complexity
- Time: $O(n + m)$
- Space: $O(n + m)$
