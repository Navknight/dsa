---
link: https://leetcode.com/problems/copy-list-with-random-pointer/
difficulty: Medium
topics:
  - "[[Linked Lists]]"
  - "[[Hash Maps]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "map old -> new. pass 1 create copies, pass 2 wire next and random through the map"
time: "O(n)"
space: "O(n)"
date: 2026-06-27
---

# Problem
Deep copy a list with `next` and `random` pointers.

# Approach
## HashMap, Two Pass
Pass 1 creates every copy, pass 2 wires `next` and `random` via the map. `mp[nullptr]` is `nullptr`, so nulls need no special case.

### Code
```cpp
Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mp;
    for (Node* cur = head; cur; cur = cur->next)
        mp[cur] = new Node(cur->val);
    for (Node* cur = head; cur; cur = cur->next) {
        mp[cur]->next   = mp[cur->next];
        mp[cur]->random = mp[cur->random];
    }
    return mp[head];
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## HashMap, Single Pass
Create copies on demand, check the map first.

### Code
```cpp
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    unordered_map<Node*, Node*> mp;
    Node* ans = new Node(head->val);
    Node* hPtr = head, *aPtr = ans;
    mp[hPtr] = aPtr;
    while (hPtr) {
        if (!mp.count(hPtr->next))
            mp[hPtr->next] = hPtr->next ? new Node(hPtr->next->val) : nullptr;
        aPtr->next = mp[hPtr->next];

        if (!mp.count(hPtr->random))
            mp[hPtr->random] = hPtr->random ? new Node(hPtr->random->val) : nullptr;
        aPtr->random = mp[hPtr->random];

        hPtr = hPtr->next;
        aPtr = aPtr->next;
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
