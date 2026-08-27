---
difficulty: Medium
topics:
  - Dynamic Programming
  - BFS
source: Leetcode
star: false
link: https://leetcode.com/problems/coin-change/
date: 2026-08-22
---

[[Dynamic Programming]] [[BFS]]

# Problem
Given coin denominations and a target `amount`, return the fewest number of coins needed to make up that amount, or `-1` if it can't be made.

# Approach
Not solvable by greedy in general — sorting coins and always taking the largest that fits fails whenever the denominations aren't "canonical." Counterexample: `coins=[1,3,4], amount=6` — greedy takes `4+1+1` (3 coins), but the optimal is `3+3` (2 coins). There's no way to know in advance whether a given `coins` array is canonical, so greedy can't be trusted here.

## Bottom-Up DP
`dp[i]` = fewest coins to make amount `i`. For each amount from `1` to the target, try every coin: if it fits, `dp[i] = min(dp[i], dp[i - coin] + 1)`. Initialize `dp` to `amount + 1` as a sentinel for "unreachable" (a real answer can never exceed `amount`, since in the worst case a coin of value `1` would need at most `amount` coins — so anything still at the sentinel after the fill is genuinely impossible).

### Code
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```

### Complexity
- Time: $O(\text{amount} \times \text{coins.size()})$
- Space: $O(\text{amount})$

## BFS (Equivalent Alternative)
Model amounts as nodes in an unweighted graph, each coin as an edge of cost 1. Finding the minimum number of coins to reach `amount` from `0` is then shortest-path-in-an-unweighted-graph — exactly what BFS solves, level by level. First time `amount` is reached, the current level (number of coins used so far) is the answer. Same complexity as the DP version — this is a different lens on the same problem, not an optimization.

### Code
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        vector<bool> visited(amount + 1, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            steps++;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int curr = q.front();
                q.pop();
                for (int c : coins) {
                    int next = curr + c;
                    if (next == amount) return steps;
                    if (next < amount && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};
```

### Complexity
- Time: $O(\text{amount} \times \text{coins.size()})$ — each amount visited once, each with `coins.size()` edges
- Space: $O(\text{amount})$ for `visited` and the queue
