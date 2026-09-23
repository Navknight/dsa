---
link: https://leetcode.com/problems/implement-queue-using-stacks/
difficulty: Easy
topics:
  - "[[Stack]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "push to s1, pop from s2, refill s2 from s1 only when s2 is empty"
time: "O(1) amortized"
space: "O(n)"
date: 2022-12-11
---

# Problem
Queue with two stacks.

# Approach
## Two Stacks
Push into `s1`. For pop and peek, if `s2` is empty pour `s1` into it, which reverses the order.

### Code
```cpp
MyQueue()
{
}

stack<int> s1;
stack<int> s2;

void push(int x)
{
    s1.push(x);
}

int pop()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x = s2.top();
    s2.pop();
    return x;
}

int peek()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}

bool empty()
{
    return s1.empty() && s2.empty();
}
```

### Complexity
- Time: $O(1)$ amortized, each element moves once
- Space: $O(n)$
