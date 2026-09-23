---
link: https://leetcode.com/problems/coin-change/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[BFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "greedy fails ([1,3,4], 6). dp[i] = min over coins of dp[i - c] + 1, sentinel amount + 1"
time: "O(amount * coins)"
space: "O(amount)"
date: 2026-08-22
---

# Problem
Fewest coins to make `amount`, or -1.

# Approach
Greedy fails for non-canonical coins: `[1,3,4], 6` gives `4+1+1` but `3+3` is better.

## DP
`dp[i] = min(dp[i], dp[i - coin] + 1)`. Init to `amount + 1` as unreachable, an answer can never exceed `amount`.

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
- Time: $O(amount \cdot coins)$
- Space: $O(amount)$

## BFS
Amounts are nodes, coins are edges of cost 1. First level that hits `amount` is the answer.

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
- Time: $O(amount \cdot coins)$
- Space: $O(amount)$
