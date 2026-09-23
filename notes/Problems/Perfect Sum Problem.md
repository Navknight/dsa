---
link: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "count subsets: t[i][j] = t[i-1][j] + t[i-1][j - arr[i-1]], t[i][0] = 1"
time: "O(n * sum)"
space: "O(n * sum)"
date: 2023-05-25
---

# Problem
Number of subsets summing to `sum`, mod 1e9+7.

# Approach
## Subset Sum Count
Skip + take. `t[i][0] = 1`. Same count as [[Target Sum]] uses.

### Code
```cpp
class Solution
{
public:
    int perfectSum(int arr[], int n, int sum)
    {
        int MOD = 1e9 + 7;
        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i < n + 1; i++)
        {
            t[i][0] = 1;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % MOD;
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][sum];
    }
};
```

### Complexity
- Time: $O(n \cdot sum)$
- Space: $O(n \cdot sum)$
