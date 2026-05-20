---
type: reference
topic: Cycle Detection
---

# Cycle Detection

Detect cycles in directed/undirected graphs. Floyd's tortoise-and-hare for linked lists.

## When to Use

- Directed graph: DFS with recursion stack (3-color)
- Undirected graph: DSU or DFS with parent tracking
- Linked list: Floyd's algorithm

## Template

```cpp
// Directed graph cycle detection (DFS, 3-color)
// 0=unvisited, 1=in-stack, 2=done
bool hasCycle(int u, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 1) return true;  // back edge
        if (color[v] == 0 && hasCycle(v, adj, color)) return true;
    }
    color[u] = 2;
    return false;
}

// Undirected graph cycle detection (DSU)
// Use DSU::unite — returns false if already connected (cycle)

// Floyd's cycle detection (linked list)
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "Cycle Detection")
sort difficulty asc, file.name asc
```
