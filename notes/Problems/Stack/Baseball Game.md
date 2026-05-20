---
difficulty: Easy
topics: ["Stack"]
source: Leetcode
star: false
code: LeetCode/baseball_game.cpp
---
[[LeetCode/baseball_game.cpp]]
[[Stack]]

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings `operations`, where `operations[i]` is the `ith` operation you must apply to the record and is one of the following:

-   An integer `x`.
    -   Record a new score of `x`.
-   `'+'`.
    -   Record a new score that is the sum of the previous two scores.
-   `'D'`.
    -   Record a new score that is the double of the previous score.
-   `'C'`.
    -   Invalidate the previous score, removing it from the record.

Return _the sum of all the scores on the record after applying all the operations_.

The test cases are generated such that the answer and all intermediate calculations fit in a **32-bit** integer and that all operations are valid.


# Solution -
	I just looped through the string given and pushed all the integers into a stack, then if there was a C, I popped the last element. 
	If there is a +, add the last two elements.
	If there is a D, double the last element and record it

```
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
