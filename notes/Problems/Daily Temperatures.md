---
link: https://leetcode.com/problems/daily-temperatures/
difficulty: Medium
topics:
  - "[[Stack]]"
  - "[[Monotonic Stack]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "monotonic stack of indices, pop while current is warmer and set their answer"
time: "O(n)"
space: "O(n)"
date: 2026-05-28
---

# Problem
Days until a warmer temperature for each day.

# Approach
## Monotonic Stack
Stack of indices. While the current temp is higher than the top, the top's answer is `i - top`, pop. Push `i`.

### Code
```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        int curr = temperatures[i];
        while (!s.empty() && temperatures[s.top()] < curr) {
            ans[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
