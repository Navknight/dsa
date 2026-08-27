---
difficulty: Easy
topics: Heap
source: LeetCode
star: false
link: https://leetcode.com/problems/last-stone-weight/description/
date: 2026-08-08
---
# Problem

# Approach
# Code
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
# Complexity
- Time: $O()$
- Space: $O()$

