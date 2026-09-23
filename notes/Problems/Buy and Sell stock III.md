---
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "dp over (index, can buy, transactions left), only the next row is needed"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Max profit with at most two transactions.

# Approach
## DP (index, buy, cap)
Like [[Buy and Sell Stock with cooldown]] but with a transaction cap. State = index, buy/sell, transactions left. Only the next row is used, so keep `prev` and `curr`.

### Code
```cpp
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy == 0)
                    curr[buy][cap] = max(-prices[i] + prev[1][cap], prev[0][cap]);
                if(buy == 1)
                    curr[buy][cap] = max(prices[i] + prev[0][cap - 1], prev[1][cap]);
            }
        }
        prev = curr;
    }

    return curr[0][2];
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
