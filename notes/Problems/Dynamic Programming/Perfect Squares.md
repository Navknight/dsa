---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/perfect-squares/"
code: ../../../LeetCode/perfect_squares.cpp
---

[[Dynamic Programming]]

# Problem
Given an integer `n`, return _the least number of perfect square numbers that sum to_ `n`.

A **perfect square** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

# Solution
This problem is exactly the same as the [[Number Of Coins]] problem. Except here the array of coins is replaced by the array of numbers up to and including the root of the given number.

```cpp
int numSquares(int n)
{
    int root = sqrt(n);
    vector<vector<int>> t(root + 1, vector<int>(n + 1, INT32_MAX - 1));

    for (int i = 0; i < root + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (j == 0 || i == 0)
                t[i][j] = 0;
            else if (i == 1)
                t[i][j] = ((j % (i * i) == 0) ? (j / (i * i)) : INT32_MAX - 1);
            else
            {
                if ((i * i) <= j)
                    t[i][j] = min(t[i][j - (i * i)] + 1, t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[root][n];
}
```