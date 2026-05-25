---
difficulty: Medium
topics:
  - Stack
source: Leetcode
star: false
link: https://leetcode.com/problems/min-stack/
date: 2026-05-25
---

[[Stack]]

# Problem

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

# Approach

Keep a stack to track what is the minimum so far in all the elements pushed to the main stack. the `minstack` gets pushed and poped at the same time as the main stack and has the min so far. kind of like a label of the "min currently" for all the elements in the main stack

# Code

```cpp
class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty())
            minSt.push(val);
        else
            minSt.push(min(minSt.top(), val));
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minSt.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

# Complexity
- Time: $O(1)$
- Space: $O(n)$