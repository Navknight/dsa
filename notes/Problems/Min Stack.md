---
link: https://leetcode.com/problems/min-stack/
difficulty: Medium
topics:
  - "[[Stack]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "second stack holding the min so far at each level"
time: "O(1)"
space: "O(n)"
date: 2026-05-25
---

# Problem
Stack with O(1) `getMin`.

# Approach
## Two Stacks
`minSt` pushes `min(top, val)` with every push and pops with every pop.

### Code
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

### Complexity
- Time: $O(1)$
- Space: $O(n)$
