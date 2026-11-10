---
link: https://leetcode.com/problems/largest-rectangle-in-histogram/
difficulty: Hard
topics:
  - "[[Arrays]]"
  - "[[Monotonic Stack]]"
source: Leetcode
star: true
blind75: false
mastery: red
review: 2026-11-11
insight: "increasing stack of indices. on a shorter bar, pop t: height h[t], width i - newTop - 1. push a 0 at the end to drain"
time: "O(n)"
space: "O(n)"
date: 2026-11-10
---

# Problem
Largest rectangle in a histogram of bar heights.

# Approach
## Monotonic Stack
A rectangle over bars `l..r` is only as tall as its shortest bar. So for each bar, find the widest span where it is the shortest: bounded by the nearest shorter bar on each side.

Keep an increasing stack of indices. When `h[i] < h[top]`, pop `t`:
- right boundary is `i`, the first shorter bar to its right
- left boundary is the new top after the pop, or `-1`
- area is `h[t] * (i - left - 1)`, both boundaries are excluded

Append a `0` height so every bar pops by the end.

- Bar `i` is not in the rectangle of the bars it pops, it is the bar that stops it. That is why the height is `h[t]` and the width has `- 1`
- Two pass version: nearest shorter on the left and on the right in two arrays, `h[i] * (right - left - 1)`. Same `O(n)`, more memory

### Mistakes
- Said the stack is decreasing. It is increasing, you pop on a shorter bar. A decreasing stack finds the next greater element
- Computed the area of bar `i` itself, with `right = i`. `i` is the right boundary of the bars being popped, not of bar `i`
- Used `h[i]` for the height and `right - left + 1` for the width, which pulls `i` into the span
- `left = s.empty() ? -1 : t` should be `s.top()` after the pop
- Forgot the leftover stack at the end
- Left an unused `int left = -1;` above the `while`, shadowed by the inner one

### Code
```cpp
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int maxArea = 0;

        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int t = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                maxArea = max(maxArea, heights[t] * (i - left - 1));
            }
            s.push(i);
        }

        return maxArea;
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
