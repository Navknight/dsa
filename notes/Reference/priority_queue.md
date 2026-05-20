---
difficulty: Unknown
topics: []
source: Standard
star: false
---

A `priority_queue` is a container adaptor that provides **constant-time access to the largest (or smallest) element**.  
It is typically implemented as a **heap** (by default, a max-heap).

---

#### Declaration

```cpp
#include <queue>
priority_queue<int> pq;  // max-heap by default
```

---

#### Common operations

|Operation|Description|Time Complexity|
|---|---|---|
|`pq.push(x)`|Insert element|O(log n)|
|`pq.pop()`|Remove top (largest/smallest)|O(log n)|
|`pq.top()`|Access top element|O(1)|
|`pq.empty()`|Check if empty|O(1)|
|`pq.size()`|Number of elements|O(1)|

---

#### Max-heap (default)

Stores the largest element at the top.

```cpp
priority_queue<int> pq;
pq.push(5);
pq.push(1);
pq.push(10);
cout << pq.top(); // 10
```

---

#### Min-heap

Use `greater<T>` as the comparison function.

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(5);
pq.push(1);
pq.push(10);
cout << pq.top(); // 1
```

---

#### Custom comparator

You can define your own comparison logic:

```cpp
struct Compare {
    bool operator()(int a, int b) const {
        return a > b; // creates a min-heap
    }
};
priority_queue<int, vector<int>, Compare> pq;
```

---

#### Key points

- Implemented using `std::vector` and `std::make_heap` internally.
    
- Does **not** allow random access or iteration like other containers.
    
- Used when you need fast access to the maximum or minimum element (e.g., heaps, scheduling, top-k problems, median maintenance).