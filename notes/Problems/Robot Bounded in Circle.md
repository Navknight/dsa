---
link: https://leetcode.com/problems/robot-bounded-in-circle/
difficulty: Medium
topics:
  - "[[Math]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "after one pass, bounded if back at origin or not facing north"
time: "O(n)"
space: "O(1)"
date: 2023-05-17
---

# Problem
Robot repeats `G`, `L`, `R` forever. Does it stay in a circle?

# Approach
## Simulate One Pass
Track `x`, `y`, `dir`. Bounded if it ends at the origin or faces any direction other than north.

### Code
```cpp
bool isRobotBounded(string instructions)
{
    int x = 0, y= 0, dir = 0;
    for(char i : instructions){
        if(i == 'G'){
            if(dir == 0)
                y++;
            else if(dir == 1)
                x++;
            else if(dir == 2)
                y--;
            else x--;
        }
        if(i == 'L'){
            dir--;
            if(dir < 0)
                dir = 3;
        }
        if(i == 'R'){
            dir++;
            dir = dir%4;
        }
    }
    if(x == 0 && y == 0)
        return 1;
    if(dir > 0)
        return 1;
    else return 0;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
