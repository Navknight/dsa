---
difficulty: Medium
topics: ["Matrix", "Recursion", "Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/unique-paths/?envType=study-plan-v2&envId=dynamic-programming"
code: LeetCode/unique_paths.cpp
---
[[LeetCode/unique_paths.cpp]]
[[Matrix]] [[Recursion]] [[Dynamic Programming]]
## Backtracking 
- The first solution is to use the usual backtracking logic used to find the number of combinations of given numbers. Assume each downward move to be represented by a 0 and each rightward move to be represented by 1. Then we can represent the movement of the bot by a string of 1's and 0's
```cpp
void backtrack(int m, int n, string &path, set<string> &paths, int size)
{
    if (path.size() == size)
    {
        paths.insert(path);
    }
    else
    {
        if (m > 1)
        {
            path.push_back(1);
            backtrack(m - 1, n, path, paths, size);
            path.pop_back();
        }
        if (n > 1)
        {
            path.push_back(0);
            backtrack(m, n - 1, path, paths, size);
            path.pop_back();
        }
    }
}
```
Here `size = m + n -2` which is the number of steps the bot has to take.
![[Pasted image 20230530163239.png]]

## DP-Table 
The second solution is to use . In this solution we create a matrix of the size `MxN` and we traverse the matrix in reverse order, i.e. - we start from the finish point and move backward in row major fashion to the bot. In each cell we represent the number of ways we can reach the finish from that cell. Now, for each cell this number will be equal to the sum of the number of ways for the immediate right and bottom cells, as at any given cell the bot has only two choices - Down or Right.
This also means that the number of ways for all the cells in the bottom row and the right most column is 1, as they can only move in one direction. This gives the base of our dp.
```cpp
vector<vector<int>> t(m, vector<int>(n, 0));
    for (int i = t.size() - 1; i >= 0; i--)
    {
        for (int j = t[0].size() - 1; j >= 0; j--)
        {
            if (i == t.size() - 1 || j == t[0].size() - 1)
                t[i][j] = 1;
            else
            {
                int x = 0, y = 0;
                if (i + 1 < t.size())
                    x = t[i + 1][j];
                if (j + 1 < t[0].size())
                    y = t[i][j + 1];
                t[i][j] = x + y;
            }
        }
    }
    return t[0][0];
```

![[Pasted image 20230530163705.png]]

There is a significant performance difference between the backtracking solution (which recalculates a lot of the same values and also has a performance overhead for using the set data structure) and the DP solution (it doesn't recalculate and is a O(MxN) solution.)