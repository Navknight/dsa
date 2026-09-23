---
link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "try every split k in [i, j), cost = left + right + arr[i-1] * arr[k] * arr[j], memo on (i, j)"
time: "O(n³)"
space: "O(n²)"
date: 2023-08-04
---

# Problem
Min multiplications to multiply a chain of matrices with dimensions `arr`.

# Approach
## Interval DP
`mcm(i, j)` = min cost for matrices `i..j`. Try every split `k`, add the cost of multiplying the two results: `arr[i-1] * arr[k] * arr[j]`. Start at `i = 1, j = n - 1`. Same shape as [[Burst Balloons]].

### Code
```cpp
// recusrion
int mcm(int i, int j, int arr[], vector<vector<int>> &t)
{
    if (t[i][j] != -1)
        return t[i][j];

    int mini = INT32_MAX;

    if (i >= j)
        return 0;
    else
    {
        for (int k = i; k < j; k++)
        {
            int temp = mcm(i, k, arr, t) + mcm(k + 1, j, arr, t) + arr[i - 1] * arr[k] * arr[j];
            mini = min(temp, mini);
        }
    }
    return t[i][j] = mini;
}

int matrixMultiplication(int n, int arr[])
{
    vector<vector<int>> t(n, vector<int>(n, -1));
    return mcm(1, n - 1, arr, t);
}
```

### Complexity
- Time: $O(n^3)$
- Space: $O(n^2)$
