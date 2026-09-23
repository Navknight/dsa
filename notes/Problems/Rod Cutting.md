---
link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "unbounded knapsack where piece length i has weight i and value price[i-1]"
time: "O(n²)"
space: "O(n²)"
date: 2023-07-11
---

# Problem
Max value from cutting a rod of length `n` into pieces with given prices.

# Approach
## Unbounded Knapsack
Piece length `i` = weight `i`, value `price[i-1]`, reusable. See [[Knapsack with Duplicate Items]].

### Code
```cpp
int cutRod(int price[], int n)
{
    vector<vector<int>> t(n+1, vector<int>(n+1));
    for (int i = 0; i < n+1 ; i++) {
        for (int j = 0; j < n+1 ; j++) {
            if(i == 0 || j ==0){
                t[i][j] = 0;
                continue;
            }
            else if(i <= j){
                t[i][j] = max(price[i-1] + t[i][j-i], t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][n];
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n^2)$
