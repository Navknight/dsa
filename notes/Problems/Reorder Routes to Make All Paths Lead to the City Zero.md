---
link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[DFS]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "add each edge both ways, original direction costs 1. DFS from 0 and sum the costs"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Tree with directed roads. Min roads to flip so every city reaches city 0.

# Approach
## DFS with Edge Costs
Store `a -> b` with cost 1 and `b -> a` with cost 0. DFS from 0, every cost-1 edge used points away from 0 and needs a flip.

### Complexity
- Time: $O(n)$
- Space: $O(n)$
