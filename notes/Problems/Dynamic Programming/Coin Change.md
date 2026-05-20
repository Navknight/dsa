---
difficulty: Medium
topics: ["Dynamic Programming", "BFS"]
source: Leetcode
star: false
---

[[Dynamic Programming]] [[BFS]]

[Coin Change]([Coin Change - LeetCode](https://leetcode.com/problems/coin-change/submissions/934571154/)) 
use an array to keep track of the number of coins required for each amount from 0 to amount called dp. Traverse this array while checking the coins array simoultaneously and take the minimum of the number of coins required.