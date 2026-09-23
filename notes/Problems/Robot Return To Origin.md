---
link: https://leetcode.com/problems/robot-return-to-origin/
difficulty: Easy
topics:
  - "[[Strings]]"
  - "[[Math]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "count U == D and L == R"
time: "O(n)"
space: "O(1)"
date: 2023-05-13
---

# Problem
Does the robot end at the origin after the moves?

# Approach
## Count
Back at origin iff `U == D` and `L == R`.

### Code
```cpp
bool judgeCircle(string moves)
{
    int u = 0;
    int d = 0;
    int r = 0;
    int l = 0;

    for (char i : moves)
    {
        if (i == 'U')
            u++;
        if (i == 'D')
            d++;
        if (i == 'R')
            r++;
        if (i == 'L')
            l++;
    }

    return (u == d && l == r);
}
```
