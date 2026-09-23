---
type: reference
topic: Knapsack
---

# Knapsack

Pick a subset of items under a capacity constraint. 0/1 = each item used once. Unbounded = items reusable.

## Identify
- Array of items + a target/sum/capacity
- Each item: include or exclude
- Reusable → Unbounded. Once only → 0/1

## Method (Aditya Verma)
1. Return type → inputs → base condition → choice diagram, in that order
2. **Base condition** = smallest valid input, not "count down from n." E.g. `n==0` or `cap==0` → profit `0`
3. **Choice diagram**: draw before coding:
   - `wt[i] > cap` → only one branch: skip
   - `wt[i] <= cap` → two branches: skip (`solve(i-1, cap)`) or take (`val[i] + solve(i-1, cap-wt[i])`)

**Example:** `wt=[1,3,4,5]`, `val=[1,4,5,7]`, `cap=7`
- item 4 (`wt=5`) fits → take it (`7 + solve(cap=2)`) or skip it (`solve(cap=7)`), take the max
- best answer: items 2+3 (`wt=3+4=7`, `val=4+5=9`)

## Template (0/1, max value)
```cpp
int knapsack01(vector<int>& wt, vector<int>& val, int cap) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int c = 0; c <= cap; c++) {
            dp[i][c] = dp[i - 1][c];
            if (wt[i - 1] <= c)
                dp[i][c] = max(dp[i][c], val[i - 1] + dp[i - 1][c - wt[i - 1]]);
        }
    return dp[n][cap];
}
```

## 1D space-optimized
- **0/1:** loop `cap` descending: each item used once. See [[Partition Equal Subset Sum]].
- **Unbounded:** loop `cap` ascending: same item reusable.

```cpp
// 0/1 subset sum
for (int w : wt)
    for (int c = target; c >= w; c--)
        dp[c] = dp[c] || dp[c - w];

// Unbounded, e.g. coin change min coins
for (int coin : coins)
    for (int c = coin; c <= target; c++)
        if (dp[c - coin] != INT_MAX)
            dp[c] = min(dp[c], dp[c - coin] + 1);
```

## Variants
- Subset Sum / Partition Equal Subset Sum: some subset hits a target
- Count of Subsets with Given Sum
- Minimum Subset Sum Difference
- Target Sum (+/- to reach a value)
- Coin Change: min coins / count ways (Unbounded)
- Rod Cutting (Unbounded)

## Playlist (Aditya Verma)
Only video 1 has captions, rest unverified against transcript.

1. [Knapsack Recursive](https://www.youtube.com/watch?v=kvyShbFVaY8)
2. [Knapsack Memoization](https://www.youtube.com/watch?v=fJbIuhs24zQ)
3. [Knapsack Bottom-up](https://www.youtube.com/watch?v=ntCGbPMeqgg)
4. [Subset Sum](https://www.youtube.com/watch?v=_gPcYovP7wc)
5. [Equal Sum Partition](https://www.youtube.com/watch?v=UmMh7xp07kY)
6. [Count of Subsets Given Sum](https://www.youtube.com/watch?v=F7wqWbqYn9g)
7. [Minimum Subset Sum Diff](https://www.youtube.com/watch?v=-GtpxG6l_Mc)
8. [Count of Subsets Given Diff](https://www.youtube.com/watch?v=ot_XBHyqpFc)
9. [Target Sum](https://www.youtube.com/watch?v=Hw6Ygp3JBYw)
10. [Unbounded Knapsack](https://www.youtube.com/watch?v=aycn9KO8_Ls)
11. [Rod Cutting](https://www.youtube.com/watch?v=SZqAQLjDsag)
12. [Coin Change: Max Ways](https://www.youtube.com/watch?v=I4UR2T6Ro3w)
13. [Coin Change: Min Coins](https://www.youtube.com/watch?v=I-l6PBeERuc)

## Problems
```base
filters:
  and:
    - file.inFolder("notes/Problems")
    - file.hasLink(this.file)
views:
  - type: table
    name: Problems
    order:
      - file.name
      - insight
      - time
      - difficulty
      - star
      - mastery
```
