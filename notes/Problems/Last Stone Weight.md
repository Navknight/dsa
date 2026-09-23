---
link: https://leetcode.com/problems/last-stone-weight/
difficulty: Easy
topics:
  - "[[Heap]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "max heap, smash the top two, push back the difference"
time: "O(n log n)"
space: "O(n)"
date: 2026-08-08
---

# Problem
Smash the two heaviest stones until at most one is left. Return its weight or 0.

# Approach
## Max Heap
Pop two, push back `x - y` if non-zero.

### Code
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone: stones) pq.push(stone);

        cout<<pq.size()<<endl;

        while(pq.size() > 1) {
            int top = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            cout<<top<<" "<<second<<endl;
            if(top - second > 0) pq.push(top - second);
        }

        return pq.size() > 0 ? pq.top() : 0;
    }
};
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
