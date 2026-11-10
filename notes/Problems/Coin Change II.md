---
link: https://leetcode.com/problems/coin-change-ii/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery: red
review: 2026-11-11
insight: "coins in the outer loop, amounts ascending inside. counts combinations, not permutations"
time: "O(n * amount)"
space: "O(amount)"
date: 2026-09-01
---

# Problem
Count combinations of coins (unlimited supply) that make `amount`. Order doesn't matter.

# Approach
Unbounded knapsack, counting. Coins processed in a fixed order so `{1,2}` and `{2,1}` are one path.

## Recursion
Skip the coin (`ind + 1`) or take it and stay (`ind`, reuse).

### Code
```cpp
class Solution {
public:
    int solve(vector<int>& coins, int amount, int sum, int ind) {
        if (sum > amount || ind >= coins.size()) return 0;
        if (sum == amount) return 1;

        return solve(coins, amount, sum, ind + 1) +
               solve(coins, amount, sum + coins[ind], ind);
    }

    int change(int amount, vector<int>& coins) {
        return solve(coins, amount, 0, 0);
    }
};
```

### Complexity
- Time: $O(2^{amount})$
- Space: $O(n + amount)$

## Memoization
Cache on `dp[ind][sum]`. Trap: keying on `amount` instead of `sum` collapses states, `amount` never changes.

### Code
```cpp
class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int sum, int ind) {
        if (sum > amount || ind >= coins.size()) return 0;
        if (dp[ind][sum] != -1) return dp[ind][sum];
        if (sum == amount) return dp[ind][sum] = 1;

        return dp[ind][sum] = solve(coins, amount, sum, ind + 1) +
                              solve(coins, amount, sum + coins[ind], ind);
    }

    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(coins, amount, 0, 0);
    }
};
```

### Complexity
- Time: $O(n \cdot amount)$
- Space: $O(n \cdot amount)$

## Tabulation 2D
`dp[i][c]` = ways to make `c` with the first `i` coins. Take = same row `dp[i][c - coin]`. Skip = `dp[i-1][c]`. The two counts add.

- Amount 0 has one way in every row. Set `dp[0][0] = 1` only and the skip term fills the column, or set the whole column and start `c` at 1. Setting the column and also looping from `c = 0` adds the skip term on top, `dp[1][0]` becomes 2
- Coins outside, amounts inside. Swapping the loops counts permutations, `amount = 3, [1,2]` gives 3 not 2

### Mistakes
- Thought it was yes/no and used a boolean array. It counts combinations, `[1,2,5]` with 5 is 4
- The transition had `+ 1` and never read the row above. Counts add, there is no `+ 1`
- `n` rows with `return dp[n][amount]`, needs `n + 1`
- Inner loop `j < amount` never fills the answer cell
- Left out the skip term `dp[i-1][c]`
- Base case applied twice: `dp[i][0] = 1` for every row, then the loop added the skip term on top, returned 10

### Code
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int c = 0; c <= amount; c++) {
                dp[i][c] = dp[i - 1][c];
                if (coins[i - 1] <= c) {
                    dp[i][c] += dp[i][c - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};
```

### Complexity
- Time: $O(n \cdot amount)$
- Space: $O(n \cdot amount)$

## 1D
Coins outside = combinations. Sum ascending inside = unbounded reuse.

### Code
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins) {
            for (int sum = coin; sum <= amount; sum++) {
                dp[sum] += dp[sum - coin];
            }
        }

        return dp[amount];
    }
};
```

### Complexity
- Time: $O(n \cdot amount)$
- Space: $O(amount)$
