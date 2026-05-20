---
difficulty: Easy
topics: ["Dynamic Programming"]
source: Leetcode
star: false
code: LeetCode/min_cost_climbing_stairs.cpp
---
[[LeetCode/min_cost_climbing_stairs.cpp]]
[[Dynamic Programming]]

[Min Cost Climbing Stairs - LeetCode](https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan-v2&id=dynamic-programming)
1.   - use a hash map to memorise previously calculated values for the respective numbers in the array cost. as the original funciton doesnt have a parameter for the index i, we need to create a new function which taked the cost array and an index i, the i^th index is the index for which we are calculating the minimum cost. This way we can calculate the minimum cost of n, n-1th element of cost array and take the minimum of those two to find the final cost.
2. Another way is to not use recursion but open up the recursion into a simple for loop. for each element with i>=2, we calculate min(cost[i-1], cost[i-2]) and add it to that elements cost, this does essentially the same thing as recursion but destroys the cost array in the process. To get the final answer we again take the minimum of cost of n-1 and nth element.