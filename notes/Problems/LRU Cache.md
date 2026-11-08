---
link: https://leetcode.com/problems/lru-cache/
difficulty: Medium
topics:
  - "[[Linked Lists]]"
  - "[[Hash Maps]]"
source: Leetcode
star: false
blind75: false
mastery: green
review: 2026-11-15
insight: "list for usage order + map key -> {value, list iterator}, erase and push_back on access"
time: "O(1)"
space: "O(capacity)"
date: 2026-06-28
---

# Problem
LRU cache with O(1) `get` and `put`.

# Approach
## List + HashMap
`std::list` is a doubly linked list: front = LRU, back = MRU. Map `key -> {value, iterator}`. On access erase the node and push to the back. Evict from the front. List iterators stay valid when other nodes are erased.

- Need O(1) removal from the middle: doubly linked list + map to the node
- Evict: read `order.front()` before `pop_front()`, then erase it from the map
- `splice(order.end(), order, it)` moves the node and keeps `it` valid. No erase and re-store of the iterator
- Keep the `find` result instead of `mp[key]` three times

### Mistakes
- First thought was a max heap. The victim is the smallest timestamp, and a heap can't update a key in the middle, so lazy deletion and O(log n)
- Second thought was a deque. O(1) at the ends only, finding and removing a middle node is O(n)

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
- Time: $O(1)$
- Space: $O(capacity)$
