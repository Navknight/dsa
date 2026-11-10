---
link: https://leetcode.com/problems/min-stack/
difficulty: Medium
topics:
  - "[[Stack]]"
source: Leetcode
star: false
blind75: false
mastery: yellow
review: 2026-11-11
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

## Stack of Pairs
Same idea in one stack: each entry is `{val, min so far}`. A pop returns the stack to its state before the push, so the new top already holds the right min.

Mistakes I made (re-solve 2026-11-08):
- First tried a min-heap with a count map, or a `min` variable with a frequency map. Both are $O(\log n)$ at best, a plain frequency map can't find the next min in $O(1)$. Pops come in reverse order of pushes, so store the min with each element.
- `st.top()` on an empty stack is undefined. The first push needs `{val, val}`.
- A local named `top` inside `push` shadows the method. Use `st.top().second`.

Cheaper in space: push to the min stack only when `val <= min` and pop it only when the popped value equals its top (use `<=`, not `<`). Or one stack of `val - min` with a `long long` min, a negative entry marks a new min.

### Code
```cpp
class MinStack {
    stack<pair<int, int>> st;

   public:
    MinStack() {}

    void push(int val) {
        if (!st.empty()) {
            auto [top, topmin] = st.top();
            int newmin = min(topmin, val);
            st.push({val, newmin});
        } else {
            st.push({val, val});
        }
    }

    void pop() { st.pop(); }

    int top() {
        auto [top, topmin] = st.top();
        return top;
    }

    int getMin() {
        auto [top, topmin] = st.top();
        return topmin;
    }
};
```

### Complexity
- Time: $O(1)$
- Space: $O(n)$
