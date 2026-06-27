---
difficulty: Medium
topics:
  - Linked Lists
  - Hash Maps
source: Leetcode
star: false
link: https://leetcode.com/problems/copy-list-with-random-pointer/
date: 2026-06-27
---

[[Linked Lists]] [[Hash Maps]]

# Problem
Deep copy a linked list where each node has a `next` and a `random` pointer. `random` can point to any node or null.

# Approach
## HashMap: Two Pass (Clean)
Build all copies first (pass 1), then wire `next` and `random` using the map (pass 2). `mp[nullptr]` returns `nullptr` by default via `[]` operator, so null-termination and null-random are handled implicitly.

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
- Time: O(n)
- Space: O(n)

## HashMap: Single Pass
Create copies on-demand during traversal. Check map before creating to avoid duplicates. Handles forward random pointers by pre-creating target nodes; they get wired correctly when traversal reaches them.

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
