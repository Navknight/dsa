---
link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "unbounded knapsack: on take stay on row i, t[i][j - wt] instead of t[i-1][j - wt]"
time: "O(N * W)"
space: "O(N * W)"
date: 2023-07-10
---

# Problem
Max value in a knapsack of capacity `W`, each item can be taken any number of times.

# Approach
0/1 knapsack but taking an item stays on the same item.

## Recursion
```cpp
int knapSack(int N, int W, int val[], int wt[])
{
    if (W == 0 || N == 0)
        return 0;
    else if (wt[N - 1] <= W)
    {
        return max(val[N - 1] + knapSack(N, W - wt[N - 1], val, wt), knapSack(N - 1, W, val, wt));
    }
    else
    {
        return knapSack(N - 1, W, val, wt);
    }
}

vector<vector<int>> t(1001, vector<int>(1001, -1));
int knapSack(int N, int W, int val[], int wt[]){
    if(N== 0 || W == 0){
        t[N][W] = 0;
        return t[N][W];
    }
    else if(wt[N-1] <= W){
        if(t[N][W] == -1){
            t[N][W] = max(val[N-1] + knapSack(N, W-wt[N-1], val, wt), knapSack(N-1, W, val, wt));
        }
        return t[N][W];
    }
    else{
        t[N][W] = knapSack(N-1, W, val, wt);
        return t[N][W];
    }
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> t(N + 1, vector<int>(W + 1));

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
                continue;
            }
            else if(wt[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[N][W];
}
```

### Complexity
- Time: exponential for recursion, $O(N \cdot W)$ memo and table
- Space: $O(N \cdot W)$
