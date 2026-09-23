---
link: https://www.geeksforgeeks.org/problems/number-of-coins1824/1
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "unbounded knapsack for min count, row 0 = infinity (INT_MAX - 1 so +1 doesn't overflow)"
time: "O(M * V)"
space: "O(M * V)"
date: 2023-07-11
---

# Problem
Min coins to make `V`, unlimited supply, or -1.

# Approach
## Unbounded Knapsack, Min
`t[i][j] = min(1 + t[i][j - coin], t[i-1][j])`. Row 0 = `INT_MAX - 1` so adding 1 doesn't overflow. Same problem as [[Coin Change]].

### Code
```cpp
int minCoins(int coins[], int M, int V)
{
    vector<vector<int>> t(M + 1, vector<int>(V + 1));
    for (int i = 0; i < M + 1; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = INT32_MAX - 1;
                continue;
            }
            if (j == 0)
            {
                t[i][j] = 0;
                continue;
            }
            if (i == 1)
            {
                if (j % coins[i - 1] == 0)
                    t[i][j] = j / coins[i - 1];

                else
                    t[i][j] = INT32_MAX - 1;
            }
            else if (coins[i - 1] <= j)
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);

            else
                t[i][j] = t[i - 1][j];
        }
    }
    return (t[M][V] >= INT32_MAX - 1) ? -1 : t[M][V];
}
```

### Complexity
- Time: $O(M \cdot V)$
- Space: $O(M \cdot V)$
