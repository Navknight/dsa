---
difficulty: Medium
topics:
  - Dynamic Programming
source: Leetcode
star: false
link: https://leetcode.com/problems/coin-change-ii/
date: 2026-09-01
---

[[Dynamic Programming]]

# Problem
Given coin denominations (unlimited supply of each) and a target `amount`, return the number of combinations that make up that amount. Order doesn't matter — `{1,2}` and `{2,1}` are the same combination, not two.

# Approach
Unbounded knapsack, counting variant. State is `(index into coins, sum so far)`. The key thing that makes this "combinations not permutations" instead of accidentally counting permutations: coins are always processed in a fixed left-to-right order (the index only ever moves forward), so `{1,2}` and `{2,1}` collapse into the same path through the state space.

## Recursion (Brute Force)
Two choices at each state: skip the current coin (move to next index, same sum) or take it and stay (same index, sum increases — this is what allows reuse/unbounded). Base cases: sum exceeding amount or running out of coins fails; hitting the exact sum succeeds.

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
- Time: $O(2^{\text{amount}})$ worst case — no memoization, overlapping `(ind, sum)` states get recomputed
- Space: $O(n + \text{amount})$ recursion stack

## Top-Down Memoization
Same recursion, cache on `dp[ind][sum]`. Both dimensions vary across calls, so both need to be part of the key — memoizing on `[ind][amount]` instead of `[ind][sum]` is a trap: `amount` is the fixed target, never changes, so that would collapse every different `sum` at a given `ind` into one cell and return stale results.

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
- Time: $O(n \times \text{amount})$ — each `(ind, sum)` state computed once
- Space: $O(n \times \text{amount})$ for the memo table + $O(n + \text{amount})$ recursion stack

## Bottom-Up 2D Tabulation
Flip the recursion into an iterative fill. `dp[i][c]` = ways to make sum `c` using the first `i` coins. `dp[i][0] = 1` for every `i` (empty selection always makes `0`). Transition: skip coin `i-1` (`dp[i-1][c]`) or take it and stay on row `i` (`dp[i][c - coins[i-1]]`, unbounded reuse via same-row lookup).

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
- Time: $O(n \times \text{amount})$
- Space: $O(n \times \text{amount})$

## Bottom-Up 1D Space-Optimized (Optimal)
`dp[i][c]` only ever reads `dp[i-1][c]` (row above) and `dp[i][c - coin]` (same row, to the left) — the row dimension collapses. Loop coins on the outside (locks in left-to-right processing order → combinations, not permutations) and capacity ascending on the inside (lets `dp[c - coin]` already reflect earlier updates from this same coin → unbounded reuse).

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
- Time: $O(n \times \text{amount})$
- Space: $O(\text{amount})$
