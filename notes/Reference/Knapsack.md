---
type: reference
topic: Knapsack
---

# Knapsack

DP pattern for "pick a subset of items under a capacity/target constraint." Two families: 0/1 (each item used once) and Unbounded (items reusable). Structure follows Aditya Verma's knapsack playlist progression.

## Identifying a Knapsack Problem
- An array/list of items is given
- A target, sum, or capacity is given
- Each item has a binary choice: include or exclude
- 0/1 if each item usable once, Unbounded if reusable any number of times

## When to Use
- Subset Sum / Partition Equal Subset Sum (does some subset hit a target sum)
- Count of Subsets with Given Sum
- Minimum Subset Sum Difference
- Target Sum (assign +/- to reach a value)
- Coin Change — min coins / number of ways (Unbounded)
- Rod Cutting (Unbounded)

## Core recurrence (0/1)
`dp[i][cap]` = best result using items `0..i` under `cap`.
`dp[i][cap] = max/OR( dp[i-1][cap], val(i) + dp[i-1][cap - wt(i)] )` — skip item i, or take it.

## Template — 0/1 Knapsack (max value)
```cpp
int knapsack01(vector<int>& wt, vector<int>& val, int cap) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int c = 0; c <= cap; c++) {
            dp[i][c] = dp[i - 1][c];
            if (wt[i - 1] <= c)
                dp[i][c] = max(dp[i][c], val[i - 1] + dp[i - 1][c - wt[i - 1]]);
        }
    }
    return dp[n][cap];
}
```

## Space-optimized (1D)
Collapses `dp[i][*]` into a single row since each row only needs the row above it.
- **0/1:** iterate `cap` **descending** — guarantees each item used at most once (see [[Partition Equal Subset Sum]] for why ascending breaks this).
- **Unbounded:** iterate `cap` **ascending** — lets the same item be reused within the same pass, which is exactly what unbounded needs.

```cpp
// 0/1 subset-sum variant
vector<bool> dp(target + 1, false);
dp[0] = true;
for (int w : wt)
    for (int c = target; c >= w; c--)
        dp[c] = dp[c] || dp[c - w];

// Unbounded (e.g. coin change - min coins)
vector<int> dp(target + 1, INT_MAX);
dp[0] = 0;
for (int coin : coins)
    for (int c = coin; c <= target; c++)
        if (dp[c - coin] != INT_MAX)
            dp[c] = min(dp[c], dp[c - coin] + 1);
```

## Problems
```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "Dynamic Programming") and regexmatch("knapsack|subset|partition|coin change|target sum|rod cutting", lower(file.name))
sort difficulty asc, file.name asc
```
