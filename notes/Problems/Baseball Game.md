---
link: https://leetcode.com/problems/baseball-game/
difficulty: Easy
topics:
  - "[[Stack]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "stack of scores, C pops, D doubles top, + sums top two"
time: "O(n)"
space: "O(n)"
date: 2023-05-13
---

# Problem
Apply score ops (int, `+`, `D`, `C`) and return the total.

# Approach
## Stack
Push ints. `C` pops, `D` pushes 2 * top, `+` pushes sum of top two. Sum the stack at the end.

### Code
```cpp
int calPoints(vector<string> &operations)

{
    stack<int> record;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "C")
        {
            if (record.empty())
                continue;
            else
                record.pop();
        }
        else if (operations[i] == "D")
        {
            if (record.empty())
                continue;
            else
            {
                int num = record.top();
                num *= 2;
                record.push(num);
            }

        }
        else if (operations[i] == "+")
        {
            if (!record.empty())
            {
                int num1 = record.top();
                record.pop();
                int num2 = record.top();
                record.pop();
                record.push(num2);
                record.push(num1);
                int num = num1 + num2;
                record.push(num);
            }
        }
        else
        {
            int num = 0;
            bool negative = false;
            for (int j = 0; j < operations[i].size(); j++)
            {
                    if(operations[i][j] == '-' && j == 0){
                    negative = true;
                    continue;
                }
                num = num * 10 + operations[i][j] - '0';
            }
            if(negative)
                num *= -1;
            record.push(num);
        }
    }
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
