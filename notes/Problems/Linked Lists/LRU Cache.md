---
difficulty: Medium
topics:
  - Linked Lists
  - Hash Maps
source: Leetcode
star: false
link: https://leetcode.com/problems/lru-cache/
date: 2026-06-28
---

[[Linked Lists]] [[Hash Maps]]

# Problem
Design a data structure for LRU (Least Recently Used) cache with `get(key)` and `put(key, value)` : both O(1). Evict least recently used key when over capacity.

# Approach
## Doubly Linked List + HashMap
`list` in `cpp` is the same as a doubly linked list.

`list<int>` acts as usage order: front = LRU, back = MRU. HashMap stores `key → {value, iterator}` for O(1) access and O(1) splice. On any access, erase the key's node from its current position and push to back. On eviction, pop front.

Key insight: `std::list` iterators stay valid after `erase` on other nodes, safe to store them in the map permanently (only invalidated on their own erase).

### Code
```cpp
class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    list<int> order;

public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        order.erase(mp[key].second);
        order.push_back(key);
        mp[key].second = --order.end();
        return mp[key].first;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end())
            order.erase(mp[key].second);
        else if (mp.size() == capacity) {
            int lru = order.front();
            order.pop_front();
            mp.erase(lru);
        }

        order.push_back(key);
        mp[key] = {value, --order.end()};
    }
};
```

### Complexity
- Time: O(1) for both `get` and `put`
- Space: O(capacity)
