---
link: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
difficulty: Easy
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "check rows, cols and diagonals for a winner, else Pending if moves < 9, else Draw"
time: "O(1)"
space: "O(1)"
date: 
---

# Problem
Given moves on a 3x3 board, return the winner, Draw or Pending.

# Approach
## Simulate
Fill the board, check rows, columns and both diagonals. No winner and fewer than 9 moves = Pending, else Draw.

### Code
```cpp
string tictactoe(vector<vector<int>> &moves)
{
    vector<vector<int>> grid(3, vector<int>(3, 0));
    for (int i = 0; i < moves.size(); i++)
    {
        if (i % 2 == 0)
            grid[moves[i][0]][moves[i][1]] = 1;
        else
            grid[moves[i][0]][moves[i][1]] = 2;
    }

    for (int i = 0; i < grid.size(); i++)
    {
        int a = 0;
        int b = 0;
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
                a++;
            else if (grid[i][j] == 2)
                b++;
        }
        if (a == 3)
            return "A";
        if (b == 3)
            return "B";
    }

    for (int i = 0; i < grid[0].size(); i++)
    {
        int a = 0;
        int b = 0;
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[j][i] == 1)
                a++;
            else if (grid[j][i] == 2)
                b++;
        }
        if (a == 3)
            return "A";
        if (b == 3)
            return "B";
    }

    if ((grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) || (grid[0][2] == 1 && grid[1][1] == 1 && grid[2][0] == 1))
        return "A";
    if ((grid[0][0] == 2 && grid[1][1] == 2 && grid[2][2] == 2) || (grid[0][2] == 2 && grid[1][1] == 2 && grid[2][0] == 2))
        return "B";

    if (moves.size() < 9)
        return "Pending";
    return "Draw";
}
```
