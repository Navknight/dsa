---
link: https://leetcode.com/problems/lemonade-change/
difficulty: Easy
topics:
  - "[[Greedy]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "count 5s and 10s, for a 20 give 10+5 before 5+5+5"
time: "O(n)"
space: "O(1)"
date: 2023-05-18
---

# Problem
Lemonade costs 5, customers pay 5, 10 or 20. Can you always give change?

# Approach
## Greedy
Track 5s and 10s. For a 20, prefer 10 + 5, it keeps more 5s for later.

### Code
```cpp
bool lemonadeChange(vector<int> &bills)
{
    int five = 0, ten = 0;
    for(int i : bills){
        if(i == 5)
            five++;
        if(i == 10){
            if(five == 0)
                return false;
            else{
                five--;
                ten++;
            }
        }
        if(i == 20){
            if(ten == 0){
                if(five < 3)
                    return false;
                else
                    five -= 3;
            }
            else{
                if(five == 0)
                    return false;
                else{
                    five--;
                    ten--;
                }
            }
        }
    }
    return true;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
