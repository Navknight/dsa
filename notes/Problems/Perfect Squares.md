---
link: https://leetcode.com/problems/perfect-squares/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "coin change where the coins are 1, 4, 9 ... up to n"
time: "O(n√n)"
space: "O(n)"
date: 2023-08-17
---

# Problem
Least number of perfect squares summing to `n`.

# Approach
## Coin Change
Same as [[Coin Change]] with coins `1², 2², ..., √n²`.

### Code
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

### Complexity
- Time: $O(n\sqrt{n})$
- Space: $O(n)$
