---
difficulty: Hard
topics: ["Heap"]
source: Leetcode
star: false
---

[[Heap]]

using [[priority_queue]] we can create two heaps - small (max heap) and big (min heap)
they keep roughly half the elements added through the stream and we can get the median from them.

```cpp
	priority_queue<int> small;
    priority_queue<int, vector<int> , greater<int>> big;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.size() != 0 && num >= small.top())
            big.push(num);
        else small.push(num);

        if(small.size() > big.size() + 1){
            int val = small.top(); small.pop();
            big.push(val);
        }

        if(big.size() > small.size() + 1){
            int val = big.top(); big.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        if(small.size() > big.size() ) return small.top();
        else if (big.size() > small.size()) return big.top();
        else return (big.top() + small.top())/2.0;
    }
```
